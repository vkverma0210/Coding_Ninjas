/* You are given a magic grid A with R rows and C columns.
In the cells of the grid, you will either get magic juice, 
which increases your strength by | A[i][j] | points, 
or poison, which takes away | A[i][j] | strength points.
If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top - left corner cell(1, 1) 
and reach at the bottom - right corner cell(R, C).
From a cell(i, j), you can only move either one cell down or right 
i.e., to cell(i + 1, j) or cell(i, j + 1) and you can not move outside the magic grid.
You have to find the minimum number of strength points with which you will be able to reach the destination cell.*/

#include <iostream>

using namespace std;

int getMinimumStrength(int **grid, int n, int m)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m]();
    }

    dp[n - 1][m - 1] = 1;
    dp[n - 1][m - 2] = 1;
    dp[n - 2][m - 1] = 1;

    for (int i = m - 3; i >= 0; i--)
    {
        if (grid[n - 1][i + 1] < 0)
        {
            dp[n - 1][i] = dp[n - 1][i + 1] - grid[n - 1][i + 1];
        }
        else
        {
            dp[n - 1][i] = max(1, dp[n - 1][i + 1] - grid[n - 1][i + 1]);
        }
    }

    for (int i = n - 3; i >= 0; i--)
    {
        if (grid[i + 1][m - 1] < 0)
        {
            dp[i][m - 1] = dp[i + 1][m - 1] - grid[i + 1][m - 1];
        }
        else
        {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - grid[i + 1][m - 1]);
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            int right, down;
            if (grid[i][j + 1] < 0)
            {
                right = dp[i][j + 1] - grid[i][j + 1];
            }
            else
            {
                right = max(1, dp[i][j + 1] - grid[i][j + 1]);
            }

            if (grid[i + 1][j] < 0)
            {
                down = dp[i + 1][j] - grid[i + 1][j];
            }
            else
            {
                down = max(1, dp[i + 1][j] - grid[i + 1][j]);
            }

            dp[i][j] = min(right, down);
        }
    }

    int ans = dp[0][0];

    for (int i = 0; i < n; ++i)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i)
        {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j)
            {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i)
        {
            delete[] grid[i];
        }

        delete[] grid;
    }
}