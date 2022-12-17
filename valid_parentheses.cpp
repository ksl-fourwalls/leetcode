#include <iostream>
#include <stack>

using namespace std;


/*
    if lookingfor and top matches then pop
    else push
*/

class Solution {
    public:
    bool isValid(string s) {
        stack<char> validationStack;
        char lookingfor;

        for (char* strptr = (char*)s.c_str(); *strptr != '\0'; strptr++)
        {
            switch (*strptr)
            {
                case '(':
                case '{':
                case '[': 
                validationStack.push(*strptr); 
                continue;
                case ')': lookingfor = '('; break;
                case '}': lookingfor = '{'; break;
                case ']': lookingfor = '['; break;
            }
            if (validationStack.empty())
                return false;
            if (lookingfor == validationStack.top())
                validationStack.pop();
            else
                validationStack.push(*strptr);
        }

        if (validationStack.empty())
            return true;
        return false;
    }
};

int main(void)
{
    Solution s;
    cout << s.isValid("(") << endl;
    return 0;
}