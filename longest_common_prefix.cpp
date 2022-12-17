#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) 
		{
			string resultstr;
			char curchar, *to = (char*)strs[0].c_str();
			bool flag = false;

			for (int idy = 0; to[idy] != '\0'; idy++)
			{
				curchar = to[idy];
				for (int idx = 1; idx < strs.size(); idx++)
				{
					char* from = (char*)strs[idx].c_str();
					if (from[idy] != to[idy])
						flag = true;

				}
				if (!flag) resultstr += to[idy];
				else break;
			}
			return resultstr;
		}

};

int main(int argc, char *argv[])
{
	vector<string> strs = { "fucker", "fuckyou", "fuckd" };
	Solution s;

	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
