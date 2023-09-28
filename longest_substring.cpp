#include <iostream>
#include <cstring>
#include <iostream>

using namespace std;

// This code is gone optimize
#define GETBIT64(x, y) (x[y % 64] >> (y % 64) & (int64_t)1)
#define SETBIT64(x, y) (x[y % 64] |= ((int64_t)1 << (y % 64)))


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
    // ----------
    // v  vv    v
    // thisstring
    // if checkbox[strptr[idx]] > curstart:
    //    secondcopy found
    //    update curstart with checkbox[strptr[idx]] + 1
    //
	int idx, idy, result = 0;

	for (idx = 0; idx < s.size(); idx++) {
		int64_t checkbox[2] = { 0 };
		SETBIT64(checkbox, (int)s[idx]);
		for (idy = idx+1; idy < s.size(); idy++) {
			if (GETBIT64(checkbox, (int)s[idy])) {
				break;
			}
			SETBIT64(checkbox, (int)s[idy]);
		}
		result = max(result, idy-idx);
	}
        return result;
    }
};

struct SolutionInfo {
    char* input;
    int output;
};

int main(void)
{
    Solution s;
     cout << s.lengthOfLongestSubstring("abcabcbd") << endl;
    return 0;
}
