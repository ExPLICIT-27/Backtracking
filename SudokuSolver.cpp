/*
Given a non empty sudoku grid, solve and return if any solutions are present
*/
#include <bits/stdc++.h>

using namespace std;
bool isSafe(vector<vector<char>> &board, int row, int col, char digit);
bool helper(vector<vector<char>> &board, int row, int col);
void Sudoku(vector<vector<char>> &board);
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Sudoku(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
{
    // Horizontal checks
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == digit)
            return false;
    }
    // vertical checks
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
            return false;
    }
    // current grid check
    int rowStart = (row / 3) * 3, colStart = (col / 3) * 3;
    for (int i = rowStart; i <= rowStart + 2; i++)
    {
        for (int j = colStart; j <= colStart + 2; j++)
        {
            if (board[i][j] == digit)
                return false;
        }
    }
    return true;
}
bool helper(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return true;
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1, nextCol = 0;
    }
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }
    for (int i = '1'; i <= '9'; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (helper(board, nextRow, nextCol))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}
void Sudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}