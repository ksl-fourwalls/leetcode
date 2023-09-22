#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	// Given two strings s and t, return true
	// if s is a subsequence of t, or false otherwise
	//
	//
	bool isSubsequence(string s, string t) 
	{
		int idx1 = 0, idx2 = 0;
		for (; idx1 < s.size(); idx2++) 
		{
			if (idx2 >= t.size())
				return false;

			if (s[idx1] == t[idx2])
				idx1++;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	string str = "abl", t = "ahbgdc";
	printf("%s\n", s.isSequence(str, t) ? "TRUE" : "FALSE");
	return 0;
}
