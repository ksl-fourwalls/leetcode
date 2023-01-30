#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		// formula T(n+3) = Tn + T(n+1) + T(n+2)
		// first task make this program dynamic 
		//
		/*
		int tribonacci(int n) 
		{
			if (n <= 2)
				return returnval[n];
			return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
		}
		*/

		int tribonacci(int n)
		{
			int t[] = { 0, 1, 1 };
			if (n < 3) return t[n];
			for (int idx = 3; idx < n; idx++)
				t[idx % 3] = t[0] + t[1] + t[2];
			return t[0] + t[1] + t[2];
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	cout << s.tribonacci(4) << endl;
	return 0;
}
