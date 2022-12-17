#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
	public:
		int getvalue_from_stack(stack<string>& strstack) 
		{
			char* token;
			if (strstack.empty()) return 0;

			token = (char*)strstack.top().c_str();
			strstack.pop();

			return atoi(token);
		}

		int evalRPN(vector<string>& tokens)
		{
			stack<string> strStack;
			int evaluatedValue = 0, idx = 0;

			while (1)
			{
				if (isValidOperator(tokens[idx]))
					break;
				else if (idx >= tokens.size())
					return getvalue_from_stack(strStack);
				strStack.push(tokens[idx]);
				idx++;
			}

			evaluatedValue = getvalue_from_stack(strStack);

			for (; idx < tokens.size(); idx++)
			{
				if (tokens[idx].size() == 1)
				{
					switch (tokens[idx][0])
					{
						case '+': 
							evaluatedValue = getvalue_from_stack(strStack) + evaluatedValue;
							break;
						case '-': 
							evaluatedValue = getvalue_from_stack(strStack) - evaluatedValue;
							break;

						case '/': 
							evaluatedValue = getvalue_from_stack(strStack) / evaluatedValue;
							break;

						case '*': 
							evaluatedValue = getvalue_from_stack(strStack) * evaluatedValue;
							break;
						default: strStack.push(tokens[idx]);
					}
				}
				else strStack.push(tokens[idx]);
			}
			return evaluatedValue;
		}

		bool isValidOperator(string token)
		{
			switch (token[0])
			{
				case '+': case '*': case '-': case '/':
					if (token.size() == 1)
						return true;
					break;
			}
			return false;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> tokens = { 
		"2", "1", "+", "3", "*"
	};

	cout << s.evalRPN(tokens) << endl;
	return 0;
}
