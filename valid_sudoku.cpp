#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// deter mine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:

// Each row must contain the digits 1 - 9 without repetition
// Each column must contain the digits 1 - 9 without repetition
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits without repetition
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			std::bitset<9> row_check;
			std::bitset<9> col_check;
			std::bitset<9> grid_check;

			const int BOXES = 9;
			int grid_idy, grid_idx;

			for (int idy = 0; idy < BOXES; idy++)
			{
				for (int idx = 0; idx < BOXES; idx++)
				{
					if (board[idy][idx] != '.')
					{
						if (col_check[board[idy][idx] - 0x31] == true)
							return false;
						col_check.set((int)board[idy][idx] - 0x31);
					}

					if (board[idx][idy] != '.')
					{
						if (row_check[(int)board[idx][idy] - 0x31] == true)
							return false;

						row_check.set((int)board[idx][idy] - 0x31);
					}

					// y * col + x;
					grid_idy = idy / 3 * 3 + idx / 3;
					grid_idx = idy % 3 * 3 + idx % 3;		// idy increasing index by one
					if (board[grid_idy][grid_idx] != '.')
					{
						if (grid_check[(int)board[grid_idy][grid_idx] - 0x31] == true)
							return false;
						grid_check.set((int)board[grid_idy][grid_idx] - 0x31);
					}
				}
				col_check.reset();
				row_check.reset();
				grid_check.reset();
			}
			return true;
		}
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<char>> board = {
		 {'5','3','.','.','7','.','.','.','.'}
		,{'6','.','.','1','9','5','.','.','.'}
		,{'.','9','8','.','.','.','.','6','.'}
		,{'8','.','.','.','6','.','.','.','3'}
		,{'4','.','.','8','.','3','.','.','1'}
		,{'7','.','.','.','2','.','.','.','6'}
		,{'.','6','.','.','.','.','2','8','.'}
		,{'.','.','.','4','1','9','.','.','5'}
		,{'.','.','.','.','8','.','.','7','9'}
	};

	return 0;
}
