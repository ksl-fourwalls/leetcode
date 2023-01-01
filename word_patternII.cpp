// Given a pattern and a string s find if s follows the same pattern
// Here follow means a full match, such that there is a bijection between a letter in pattern
// and a non-empty word in s
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
	public:
		struct tokeninfo {
			char pattern;
			int string_index[2];
		};

		bool wordPattern(string pattern, string s)
		{
			token_ptr = (char *)s.c_str();
			for (int idx = 0; idx < pattern.size(); idx++)
				if (get_token_from_string(pattern[idx]) != pattern[idx])
					return false;

			if (start_idx < s.size())
				return false;
			return true;
		}

		bool strcmp(int* string1, int* string2)
		{
			if (string1[1]-string1[0] != string2[1]-string2[0])
				return false;

			for (int idx = string1[0], idy = string2[0]; idx < string1[1]; idx++, idy++)
				if (token_ptr[idx] != token_ptr[idy])
					return false;

			return true;
		}

		char get_token_from_string(char pattern)
		{
			struct tokeninfo tmp;

			for (tmp.string_index[0] = start_idx; token_ptr[start_idx] != '\0' && token_ptr[start_idx] != ' '; 
					start_idx++);

			// store end index of string
			tmp.string_index[1] = start_idx++;

			for (int idx = 0; idx < tokens.size(); idx++)
			{
				if (tokens[idx].pattern == pattern)
					return this->strcmp(tokens[idx].string_index, tmp.string_index) ?  pattern : -1;

				else if (this->strcmp(tokens[idx].string_index, tmp.string_index))
					return -1;

			}
			// new token found append it at the back
			tmp.pattern = pattern;
			tokens.push_back(tmp);

			return pattern;
		}

	private:
		char* token_ptr = nullptr;
		int start_idx = 0;

		vector<tokeninfo> tokens;
};



int main(int argc, char *argv[])
{
	Solution s;
	printf("%s\n", s.wordPattern("abba", "dog dog dog dog") ? "TRUE" : "FALSE");
	return 0;
}
