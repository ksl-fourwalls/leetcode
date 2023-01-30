#include <iostream>
#include <vector>

using namespace std;

bool compar(string& str1, string& str2, string& abcd)
{
	int idy, idx = 0, previdy;

	for (;;)
	{
		if (idx >= str1.size())
			break;

		if (idx >= str2.size())
			return false;

		idy = 0;
		while (1)
		{
			if (idy >= abcd.size())
				return false;

			if (abcd[idy] == str1[idx])
				break;
			idy++;
		}

		previdy = idy;

		while (1)
		{
			if (idy >= abcd.size())
				return false;

			if (abcd[idy] == str2[idx])
				break;
			idy++;
		}
		if (previdy != idy)
			return true;

		idx++;
	}
	return true;
}

class Solution {
public:


	bool isAlienSorted(vector<string>& words, string order)
	{
		for (int idx = 1; idx < words.size(); idx++)
		{
			if (!compar(words[idx-1], words[idx], order))
				return false;
		}
		return true;
	}
};

int main(int argc, char* argv[])
{
	vector<string> words = {
		"hello", "leetcode"
	};
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	Solution s;

	printf(": %s\n", s.isAlienSorted(words, order) ? "TRUE" : "FALSE");
	return 0;
}
