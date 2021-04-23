/* CodingNinjas has provided a crossword of 10 * 10 grid.
The grid contains '+' or '-' as its cell values.
Now, you are also provided with a word list that needs to placed accurately in the grid.
Cells marked with '-' are to be filled with word list. */

#include <bits/stdc++.h>

using namespace std;

#define n 10

bool check_valid_vertical(char **board, int i, int j, string word)
{
    if (10 - i < word.length())
    {
        return false;
    }
    for (int row = i; row - i < word.length() && row < n; row++)
    {
        if (board[row][j] == word[row - i] || board[row][j] == '-')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

void fill_vertically(char **board, int row, int col, int storage[], string word)
{
    for (int i = row; (i - row) < word.length() && i < n; i++)
    {
        if (board[i][col] == '-')
        {
            storage[i - row] = i;
            board[i][col] = word[i - row];
        }
    }
}

void reset_vertically(char **board, int row, int col, int storage[], string word)
{
    for (int i = row; (i - row) < word.length() && i < n; i++)
    {
        if (storage[i - row] != -1)
        {
            board[i][col] = '-';
        }
    }
}

bool check_valid_horizontal(char **board, int i, int j, string word)
{
    if (10 - j < word.length())
    {
        return false;
    }
    for (int col = j; col - j < word.length() && col < n; col++)
    {
        if (board[i][col] == word[col - j] || board[i][col] == '-')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

void fill_horizontally(char **board, int row, int col, int storage[], string word)
{
    for (int i = col; (i - col) < word.length() && i < n; i++)
    {
        if (board[row][i] == '-')
        {
            storage[i - col] = i;
            board[row][i] = word[i - col];
        }
    }
}

void reset_horizontally(char **board, int row, int col, int storage[], string word)
{
    for (int i = col; (i - col) < word.length() && i < n; i++)
    {
        if (storage[i - col] != -1)
        {
            board[row][i] = '-';
        }
    }
}

bool fill_board(char **board, vector<string> words, int index)
{
    if (index == words.size())
    {
        return true;
    }

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '-' || board[i][j] == words[index][0])
            {
                found = 1;

                // check valid vertical from that position
                if (check_valid_vertical(board, i, j, words[index]))
                {
                    int storage[words[index].length()]{};
                    for (int i = 0; i < words[index].length(); i++)
                    {
                        storage[i] = -1;
                    }

                    // fill vertically
                    fill_vertically(board, i, j, storage, words[index]);

                    //call fn again with index + 1
                    bool isPossible = fill_board(board, words, index + 1);

                    // if return true - print board
                    if (isPossible)
                    {
                        return true;
                    }

                    // else reset_vertically
                    else
                    {
                        reset_vertically(board, i, j, storage, words[index]);
                    }
                }
                else if (check_valid_horizontal(board, i, j, words[index]))
                {
                    int storage[words[index].length()]{};
                    for (int i = 0; i < words[index].length(); i++)
                    {
                        storage[i] = -1;
                    }

                    // fill horizontally
                    fill_horizontally(board, i, j, storage, words[index]);

                    //call fn again with index + 1
                    bool isPossible = fill_board(board, words, index + 1);

                    // if return true - print board
                    if (isPossible)
                    {
                        return true;
                    }

                    // else reset_horizontally
                    else
                    {
                        reset_horizontally(board, i, j, storage, words[index]);
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    char **board = new char *[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new char[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    string wordlist;
    cin >> wordlist;

    vector<string> words;

    string s;

    for (int i = 0; i <= wordlist.length(); i++)
    {
        if (wordlist[i] == ';' || i == wordlist.length())
        {
            words.push_back(s);
            s.clear();
        }
        else
        {
            s.push_back(wordlist[i]);
        }
    }

    fill_board(board, words, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }

        cout << endl;
    }

    return 0;
}