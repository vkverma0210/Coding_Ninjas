/* Given a NxM matrix containing Uppercase English Alphabets only.
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells.
For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell. */

#include <iostream>
#include <vector>
using namespace std;

bool dfs_traversal(vector<vector<char>> &board, int n, int m, int curr_n, int curr_m, bool **visited, int curr_el)
{
    if (curr_el >= 11)
    {
        return true;
    }

    visited[curr_n][curr_m] = true;

    string cn = "CODINGNINJA";

    bool ans1 = false, ans2 = false, ans3 = false, ans4 = false, ans5 = false, ans6 = false, ans7 = false, ans8 = false;

    while (true)
    {
        //Check Top
        if (curr_n - 1 >= 0)
        {
            if (board[curr_n - 1][curr_m] == cn[curr_el] && !visited[curr_n - 1][curr_m])
            {
                ans1 = dfs_traversal(board, n, m, curr_n - 1, curr_m, visited, curr_el + 1);
            }
        }

        if (ans1)
        {
            break;
        }

        // Check Bottom
        if (curr_n + 1 < n)
        {
            if (board[curr_n + 1][curr_m] == cn[curr_el] && !visited[curr_n + 1][curr_m])
            {
                ans2 = dfs_traversal(board, n, m, curr_n + 1, curr_m, visited, curr_el + 1);
            }
        }

        if (ans2)
        {
            break;
        }

        // Check Right
        if (curr_m + 1 < m)
        {
            if (board[curr_n][curr_m + 1] == cn[curr_el] && !visited[curr_n][curr_m + 1])
            {
                ans3 = dfs_traversal(board, n, m, curr_n, curr_m + 1, visited, curr_el + 1);
            }
        }

        if (ans3)
        {
            break;
        }

        // Check Left
        if (curr_m - 1 >= 0)
        {
            if (board[curr_n][curr_m - 1] == cn[curr_el] && !visited[curr_n][curr_m - 1])
            {
                ans4 = dfs_traversal(board, n, m, curr_n, curr_m - 1, visited, curr_el + 1);
            }
        }

        if (ans4)
        {
            break;
        }

        // Check Diagonal Top Right
        if (curr_n - 1 >= 0 && curr_m + 1 < m)
        {
            if (board[curr_n - 1][curr_m + 1] == cn[curr_el] && !visited[curr_n - 1][curr_m + 1])
            {
                ans5 = dfs_traversal(board, n, m, curr_n - 1, curr_m + 1, visited, curr_el + 1);
            }
        }

        if (ans5)
        {
            break;
        }

        // Check Diagonal Top Left
        if (curr_n - 1 >= 0 && curr_m - 1 >= 0)
        {
            if (board[curr_n - 1][curr_m - 1] == cn[curr_el] && !visited[curr_n - 1][curr_m - 1])
            {
                ans6 = dfs_traversal(board, n, m, curr_n - 1, curr_m - 1, visited, curr_el + 1);
            }
        }

        if (ans6)
        {
            break;
        }

        // Check Diagonal Bottom Left
        if (curr_n + 1 < n && curr_m + 1 < m)
        {
            if (board[curr_n + 1][curr_m + 1] == cn[curr_el] && !visited[curr_n + 1][curr_m + 1])
            {
                ans7 = dfs_traversal(board, n, m, curr_n + 1, curr_m + 1, visited, curr_el + 1);
            }
        }

        if (ans7)
        {
            break;
        }

        // Check Diagonal Bottom Right
        if (curr_n + 1 < n && curr_m - 1 >= 0)
        {
            if (board[curr_n + 1][curr_m - 1] == cn[curr_el] && !visited[curr_n + 1][curr_m - 1])
            {
                ans8 = dfs_traversal(board, n, m, curr_n + 1, curr_m - 1, visited, curr_el + 1);
            }
        }

        break;
    }

    visited[curr_n][curr_m] = false;
    if (ans1 == true || ans2 == true || ans3 == true || ans4 == true || ans5 == true || ans6 == true || ans7 == true || ans8 == true)
    {
        return true;
    }

    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    bool **visited = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                bool ans = dfs_traversal(board, n, m, i, j, visited, 1);
                if (ans)
                {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }

    delete[] visited;

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}