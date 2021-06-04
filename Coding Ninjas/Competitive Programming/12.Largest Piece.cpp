/* It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's .
But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. 
Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ? */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dfs_search(vector<vector<int>> &cake, int n, bool **visited, int i, int j)
{
    visited[i][j] = true;

    int ans = 0;

    //Up
    if (i - 1 >= 0)
    {
        if (cake[i - 1][j] == 1 && !visited[i - 1][j])
        {
            ans += dfs_search(cake, n, visited, i - 1, j);
        }
    }

    //Down
    if (i + 1 < n)
    {
        if (cake[i + 1][j] == 1 && !visited[i + 1][j])
        {
            ans += dfs_search(cake, n, visited, i + 1, j);
        }
    }

    //Left
    if (j - 1 >= 0)
    {
        if (cake[i][j - 1] == 1 && !visited[i][j - 1])
        {
            ans += dfs_search(cake, n, visited, i, j - 1);
        }
    }

    //Right
    if (j + 1 < n)
    {
        if (cake[i][j + 1] == 1 && !visited[i][j + 1])
        {
            ans += dfs_search(cake, n, visited, i, j + 1);
        }
    }

    return 1 + ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool **visited = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    int max_piece = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;

                int ans = dfs_search(cake, n, visited, i, j);

                if (ans > max_piece)
                {
                    max_piece = ans;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }

    delete[] visited;

    return max_piece;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}