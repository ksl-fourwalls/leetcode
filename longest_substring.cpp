#include <iostream>
#include <cstring>

using namespace std;
#define arraysize(array) (sizeof(array) / sizeof(*array))

class Solution {
    public:
    // ----------
    // v  vv    v
    // thisstring
    // if checkbox[strptr[idx]] > curstart:
    //    secondcopy found
    //    update curstart with checkbox[strptr[idx]] + 1
    //
    int lengthOfLongestSubstring(string s) {
        int checkbox[0xff];
        char* strptr = (char*)s.c_str();
        int maxlength = 0, curstart = 0, idx;

        memset(checkbox, 0, sizeof(checkbox));

        if (strptr[0] == '\0') return 0;
        for (idx = 1; strptr[idx] != '\0'; idx++)
        {
            if (checkbox[strptr[idx]] >= curstart)
            {
                maxlength = max(idx - curstart, maxlength);
                curstart = checkbox[strptr[idx]] + 1;
            }
            checkbox[strptr[idx]] = idx;
        }
        maxlength = max(idx - curstart, maxlength);
        return maxlength;
    }
};

struct SolutionInfo {
    char* input;
    int output;
};

int main(void)
{
    Solution s;
    struct SolutionInfo sinfo[] = {
        { "dvdf", 3 },
        { "abcabcbb", 3 },
        { "pwwkew", 3 },
        { "", 0 },
        { " ", 1 },
    };

    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
