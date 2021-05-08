/* Given an NxM matrix that contains only 0s and 1s, 
find out the size of the maximum square sub - matrix with all 0s. 
You need to return the size of the square matrix with all 0s. */

#include <bits/stdc++.h>

using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    //Write your code here

    if (m == 0 || n == 0)
    {
        return 0;
    }

    int **dp = new int *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m]{};
    }

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = arr[0][i] == 1 ? 0 : 1;
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0] == 1 ? 0 : 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] > maximum)
            {
                maximum = dp[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete dp[i];
    }

    delete dp;

    return maximum;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}