/* Given a 9 * 9 sudoku board, in which some entries are filled and others are 0(0 indicates that the cell is empty), 
you need to find out whether the Sudoku puzzle can be solved or not i.e.return true or false. */

#include <iostream>

using namespace std;

bool find_empty(int board[][9], int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }

    return false;
}

bool check_row(int board[][9], int i, int j, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == num)
        {
            return false;
        }
    }

    return true;
}

bool check_col(int board[][9], int i, int j, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    return true;
}

bool check_grid(int board[][9], int i, int j, int num)
{
    int checki = i >= 0 && i < 3 ? 0 : i >= 3 && i < 6 ? 3
                                                       : 6;
    int checkj = j >= 0 && j < 3 ? 0 : j >= 3 && j < 6 ? 3
                                                       : 6;
    for (int row = checki; row < checki + 3; row++)
    {
        for (int col = checkj; col < checkj + 3; col++)
        {
            if (board[row][col] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int board[][9])
{
    int row, col;
    bool found = find_empty(board, row, col);
    if (found)
    {
        // go from 1 to 9 and
        for (int i = 0; i <= 9; i++)
        {
            bool rowcheck = check_row(board, row, col, i);
            bool colcheck = check_col(board, row, col, i);
            bool gridcheck = check_grid(board, row, col, i);

            if (rowcheck && colcheck && gridcheck)
            {
                board[row][col] = i;
                bool findifvalid = sudokuSolver(board);
                if (findifvalid)
                {
                    return true;
                }
                board[row][col] = 0;
            }
        }
    }
    else
    {
        // no empty means sudoku is filled or solved
        return true;
    }

    return false;
}

int main()
{

    int n = 9;
    int board[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (sudokuSolver(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
