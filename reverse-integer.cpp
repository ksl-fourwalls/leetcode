#include <iostream>
#include <cmath>

using namespace std;

class Solution {
	public:
		int reverse(int x) {
			if (x > 0xffffffff) x &= 0x7fffffff;
			printf("%d: x\n", x);
			return x >> 31 ? -do_reverse(-x) : do_reverse(x);
		}

		int do_reverse(int x)
		{
			int reversed_num = 0, length = 0;

			for (int num = x; num > 0; num /= 10)
				length++;

			for (; x > 0; x /= 10)
				reversed_num += x % 10 * pow(10, --length);

			return reversed_num;
		}
};
int main(int argc, char *argv[])
{
	Solution s;
	cout << s.reverse(1534236469) << endl;

	return 0;
}
