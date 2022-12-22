#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

struct numinfo {
	const char inpInt;
	const char *associatedChar;
};

struct numinfo Numbers[] = {
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jki"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"},
};

class Solution {
	public:
		int num = 0;

		int loopcount[3] = { 0, 0 , 0};
		int loopsize[3] = { 3, 3, 3};

		void recursive_traversal(char* digits, int end)
		{
			if (end == 2)
			{
				for (int idx = loopcount[end]; idx < loopsize[end]; idx++)
					printf("%d, %d\n", end, idx);

				return;
			}
			for (int idx = loopcount[end]; idx < loopsize[end]; idx++)
				recursive_traversal(digits, end + 1);
		}


		vector<string> letterCombinations(string digits)
		{
			vector<string> strVec;
			int size = digits.size();
			uint8_t loopcount[size] = { 0 };

			for (int idx = 0; idx < size; idx++)
			{
			}

			return strVec;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	char buf[] = "hello";
	vector<string> strVec;
//	strVec = s.letterCombinations("242");

	s.recursive_traversal(buf, 0);
	return 0;
}
