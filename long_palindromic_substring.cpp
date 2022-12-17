#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        stack<char> thisstack;
        int left = -1, right = -1;

        for (int i = 0; i < s.size()-1; i++)
        {
            for (int j = i+1; j < s.size(); j++)
            {
                if (ispalindrome(s, i, j+1))
                {
                    if ((j - i) > (right - left))
                    {
                        left = i;
                        right = j;
                    }
                }
            }
        }

        if (left == -1 && right == -1)
            return NULL;
        return s.substr(left, right);
    }

    bool ispalindrome(string str, int left, int right) {
        stack<char> thisstack;
        int half_len, saved_left = left;

        half_len = (right - left) / 2;
        for (; left < half_len; left++)
            thisstack.push(str[left]);

        if ((right-saved_left) % 2 != 0)
            left++;

        if (!thisstack.empty())
        {
            if (thisstack.top() != str[left++])
                return false;
            thisstack.pop();
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    printf("%s\n", s.longestPalindrome("fuuf").c_str());
    return 0;
}