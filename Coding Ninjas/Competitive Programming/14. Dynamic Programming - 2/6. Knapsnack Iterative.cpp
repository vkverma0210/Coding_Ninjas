/* A thief is robbing a store and can carry a maximal weight of W into his knapsack.
There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry, 
you have to find and return the maximum value that thief can generate by stealing items. */

#include <cstring>
#include <iostream>

using namespace std;

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here

    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1]{};
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= maxWeight; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }

    int ans = dp[n][maxWeight];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        delete dp[i];
    }

    delete[] dp;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;

    return 0;
}