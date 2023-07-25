#include <iostream>
#include <cmath>

using namespace std;

class Solution  {
public:
	bool isPowerOfFour(int n) {
		if (n <= 0)
			return false;
		double value = log10((double) n) / log10((double) 4);
		return (double)((int)value) == value;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	printf("%s\n", s.isPowerOfFour(68)? "TRUE" : "FALSE");
	return 0;
}
