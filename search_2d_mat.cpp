#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
	bool savedMatrix(vector<vector<int>>& matrix, int target) {
		int l = 0, r = matrix.size() * matrix[0].size() - 1, m, col, row;
		while (l <= r)
		{ 	// y * col + x
			m = floor((l+r) / 2);
			row = m / matrix.size();
			col = m % matrix.size();

			if (matrix[row][col] < target) {
				l = m + 1;
			} else if (matrix[row][col] > target) {
				r = m - 1;
			} else {
				return true;
			}
		}
		return false;
	}

};


int main(int argc, char * argv[])
{
	Solution s;
	vector<vector<int>> matrix = {
		{1, 1}
	};
	int target = 16;

	printf("%s\n", s.savedMatrix(matrix, target) ? "TRUE" : "FALSE");
	return 0;
}
