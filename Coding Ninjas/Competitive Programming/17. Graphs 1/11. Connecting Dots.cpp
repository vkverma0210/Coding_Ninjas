/* Gary has a board of size NxM.
Each cell in the board is a coloured dot.
There exist only 26 colours denoted by uppercase Latin characters(i.e.A, B, ..., Z).
Now Gary is getting bored and wants to play a game.
The key of this game is to find a cycle that contain dots of same colour.
Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition : 
1. These k dots are different : if i ≠ j then di is different from dj.
2. k is at least 4. 
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1 : di and di + 1 are adjacent.
Also, dk and d1 should also be adjacent.
Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help.
Your task is to determine if there exists a cycle on the board. */

#include <iostream>
#include <vector>

using namespace std;

bool dfs_search(vector<vector<char>> &board, int n, int m, int i, int j, bool **visited, char curr_char)
{
    visited[i][j] = true;

    int count = 0;

    //Up
    if (i - 1 >= 0)
    {
        if (visited[i - 1][j])
        {
            count++;
        }
    }

    //Down
    if (i + 1 < n)
    {
        if (visited[i + 1][j])
        {
            count++;
        }
    }

    //Left
    if (j - 1 >= 0)
    {
        if (visited[i][j - 1])
        {
            count++;
        }
    }

    //Right
    if (j + 1 < m)
    {
        if (visited[i][j + 1])
        {
            count++;
        }
    }

    if (count >= 2)
    {
        return true;
    }

    bool ans;

    while (true)
    {
        //Check Top
        if (i - 1 >= 0)
        {
            if (board[i - 1][j] == curr_char && !visited[i - 1][j])
            {
                ans = dfs_search(board, n, m, i - 1, j, visited, curr_char);
            }
        }

        if (ans)
        {
            break;
        }

        // Check Bottom
        if (i + 1 < n)
        {
            if (board[i + 1][j] == curr_char && !visited[i + 1][j])
            {
                ans = dfs_search(board, n, m, i + 1, j, visited, curr_char);
            }
        }

        if (ans)
        {
            break;
        }

        // Check Right
        if (j + 1 < m)
        {
            if (board[i][j + 1] == curr_char && !visited[i][j + 1])
            {
                ans = dfs_search(board, n, m, i, j + 1, visited, curr_char);
            }
        }

        if (ans)
        {
            break;
        }

        // Check Left
        if (j - 1 >= 0)
        {
            if (board[i][j - 1] == curr_char && !visited[i][j - 1])
            {
                ans = dfs_search(board, n, m, i, j - 1, visited, curr_char);
            }
        }

        if (ans)
        {
            break;
        }
        
        break;
    }

    visited[i][j] = false;

    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
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
            char current = board[i][j];
            bool ans = dfs_search(board, n, m, i, j, visited, current);
            if (ans)
            {
                return true;
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}