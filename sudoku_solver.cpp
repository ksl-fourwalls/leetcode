#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

class Solution {
public:
/*
    1. Each of the digits 1-9 must occur exactly once in each row
    2. Each of the digits 1-9 must occur exactly once in each column
    3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid
*/
    void solveSudoku(vector<vector<char>>& board) 
    {
        fillSudoku(board, 0, 0);
    }

    int fillSudoku(vector<vector<char>>& board, int row, int col)
    {

    }


    int isAvailable(vector<vector<char>>& board, int row, int col, int num)
    {
        int rowStart = (row / 3) * 3;
        int colStart = (col / 3) * 3;

        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num) return 0;
            if (board[i][col] == num) return 0;
            if (board[rowStart + (i % 3)][colStart + (i / 3)] == num) return 0;
        }

        return 1;
    }

    void printBoard(vector<vector<char>>& board)
    {
        for (int idy = 0; idy < 9; idy++)
        {
            for (int idx = 0; idx < 9; idx++)
                cout << board[idy][idx] << " ";
            cout << "\n";
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<char>>board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(board);
    s.printBoard(board);
    return 0;
}