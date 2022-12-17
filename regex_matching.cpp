#include <iostream>
#include <cstdint>
#include <cassert>
#include <stack>
#include <climits>

using namespace std;

/*
 * the precedence from highest to lowest is:
 * 1. Closure (Kleene star) a*
 * 2. Concatenation ab
 * 3. Union a+b
 */

class Solution {
    public:
    bool isMatch(string s, string p)
    {
	    return false;
    }
};

/*
 a, b
 -----
 |   |
 |   v
--------             --------                  --------
|      |     b       |      |        b         |------|
|  q0  |------------>|  q1  |----------------->|| q2 ||
|      |             |      |                  |------|
--------             --------                  --------
*/

bool isoperator(char symbol)
{
	switch (symbol)
	{
		case '(':
		case ')':
		case '*':
		case '+':
			return true;
	}
	return false;
}

string identifiableRegexString(const char* regexString)
{
	string tmpStr;

	tmpStr += *regexString;
	for (int idx = 1; regexString[idx] != '\0'; idx++)
	{
		if (!isoperator(regexString[idx-1]) && !isoperator(regexString[idx]))
			tmpStr += '?';
		tmpStr += regexString[idx];
	}
	return tmpStr;
}



int main(int argc, char* argv[])
{
/*
Solution s;
cout << s.isMatch("aaa", "ab*ac*a") << endl;
*/ 	
//	regex2nfa("ab*ac*a");
	std::cout << identifiableRegexString("a(a+b)*b") << std::endl;
	return 0;
}
