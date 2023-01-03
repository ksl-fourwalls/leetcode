// You are given an array of n strings strs, all of the same length
// The strings can be arranged such that there is one on each line,
// making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as
//
// abc
// bce 
// cae

// You want to delete the columns that are not sorted lexicographically. In the
// above example (0-indexed), columns O('a', 'b', 'c') and 2('c', 'e', 'e') are
// sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1
//
//
// Return the number of columns that you will delete

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int minDeletionSize(vector<string>& strs) {
			char prevchar;
			int subvalue, mindelete = 0, idx = 0;

			if (strs.size() == 0) 
				return mindelete;

			while (true)
			{
				if (idx >= strs[0].size())
					goto out;

				prevchar = strs[0][idx];
				for (int idy = 1; idy < strs.size(); idy++)
				{
					if (idx >= strs[idy].size())
						goto out;
					if (strs[idy][idx] - prevchar < 0)
					{
						mindelete++;
						break;
					}

					// strs
					prevchar = strs[idy][idx];
				}
				idx++;
			}
out: 			return mindelete;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> strs = {
		"cba",
		"daf",
		"ghi"
	};
	cout << s.minDeletionSize(strs) << endl;
	return 0;
}
