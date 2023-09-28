#include <iostream>
#include <cstring>
#include <iostream>

using namespace std;
#define arraysize(array) (sizeof(array) / sizeof(*array))


#define GETBIT(x, y) ((x >> y) & (int64_t)1)
#define SETBIT(x, y) (x |= ((int64_t)1 << y))

struct checkbox{
	int64_t first, second;
};

#define SETBIT128(x, y) (y >= 64 ? SETBIT(x.first, y-64): SETBIT(x.second, y))
#define GETBIT128(x, y) (y >= 64 ? GETBIT(x.first, y-64): GETBIT(x.second, y))

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
		checkbox checkboxinfo = { 0 };
		SETBIT128(checkboxinfo, (int)s[idx]);
		for (idy = idx+1; idy < s.size(); idy++) {
			if (GETBIT128(checkboxinfo, (int)s[idy])) {
				break;
			}
			SETBIT128(checkboxinfo, (int)s[idy]);
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
