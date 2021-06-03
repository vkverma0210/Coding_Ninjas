/* Given a NxM matrix containing Uppercase English Alphabets only.
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells.
For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell. */

#include <iostream>
#include <vector>
using namespace std;

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs_traversal(edges, n, visited, i);
            count++;
        }
    }

    delete[] visited;

    return count;
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