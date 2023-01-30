#include <iostream>
#include <vector>

using namespace std;

bool consume_string(string& source, string& token)
{
	int idx = 0;
	while (idx < source.size())
	{
		if (token[idx % token.size()] != source[idx])
			return false;
		idx++;
	}
	if (idx % token.size() != 0)
		return false;
	return true;
}


class Solution {
public:
	string gcdOfStrings(string str1, string str2)
	{
		string token;
		for (int idx = 0; idx < str1.size() && idx < str2.size(); idx++)
		{
			if (str1[idx] == str2[idx])
				token += str1[idx];
			else break;
		}

		while (token.size() >= 1)
		{
			if (consume_string(str1, token) && consume_string(str2, token))
				return token;
			else token.pop_back();
		}
		return "";
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	cout << s.gcdOfStrings("ABCABC", "ABC") << endl;
	return 0;
}
