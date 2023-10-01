#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string reverseWords(string s)  {
		string result;
		int start = 0;

		for (int idx = 0; idx < s.size(); idx++) 
		{
			if (s[idx] == ' ')
			{
				reverse(result.begin() + start, result.begin() + idx);
				start = idx+1;
			} 
			result += s[idx];
		}
		reverse(result.begin() + start, result.end());
		return result;

	}
};

int main(int argc, char* argv[]) {
	Solution s;
	string str = "God Ding";
	cout << s.reverseWords(str) << endl;
	return 0;
}
