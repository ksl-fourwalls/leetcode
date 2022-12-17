#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
    public:
    int myAtoi(string s) {
        char* ptr = (char*)s.c_str(), *start;
        int tInteger = 0, cutoff, cutlim;
        bool positive = true;
        const int base = 10;

        for (; isspace(*ptr) && *ptr != '\0' ; ptr++);
        if (*ptr == '-') {
            positive = false;
            ptr++;
        }

        cutoff = positive ? INT_MAX : -INT_MAX;
        cutlim = INT_MAX % base;
        cutoff /= (unsigned int)base;
        for (int c; *ptr != '\0'; ptr++)
        {
            c = *ptr - 0x30;
            if (isdigit(*ptr))
            {
                if (tInteger > cutoff || tInteger == cutoff && c > cutlim)
                    tInteger /= cutlim;

                tInteger *= base;
                tInteger += c;
            }
        }
        return positive ? tInteger : -tInteger;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.myAtoi("-91283472332") << endl;
}