#include <iostream>
#include <vector>

using namespace std;

const char *alpha[] = {
	" ", "'", 
	"abc", "def", "ghi",
	"jkl", "mno", "pqrs",
	"tuv", "wxyz"
};

struct {
	string buf;
	vector<string> m_Str;
	char* digits;
} glob;

void combination(int index)
{
	if (glob.digits[index] == '\0')
	{
		glob.m_Str.push_back(glob.buf);
		return;
	}

	for (char* ptr = (char*)alpha[glob.digits[index]-0x30]; *ptr != '\0'; ptr++)
	{
		glob.buf += *ptr;
		combination(index+1);
		glob.buf.pop_back();
	}
}

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		glob.digits = digits.c_str();
		if (digits.size() > 0)  // testcase also contain empty digit input
			combination(0);
		return glob.m_Str;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<string> m_data = s.letterCombinations(digits);

	for (auto& data: m_data)
		printf("%s\n", data.c_str());

	return 0;
}
