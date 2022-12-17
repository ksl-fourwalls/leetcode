#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) 
    {
        int len, second_half;

        if (x = 0) return false;
        if (!x) return true;

        len = trunc(log10(x)) + 1;

        second_half = 0;
        for (int idx = 0; idx < len / 2; idx++, x /= 10)
        {
            second_half *= 10;
            second_half += x % 10;
        }
        if (len % 2 != 0)
            x /= 10;

        return second_half == x;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.isPalindrome(1001));
}
