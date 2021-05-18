/* A thief is robbing a store and can carry a maximal weight of W into his knapsack.
There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry, 
you have to find and return the maximum value that thief can generate by stealing items. */

#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

int helperKnapsack(int *weight, int *value, int n, int maxWeight, ll **dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }

    if (weight[n] <= maxWeight)
    {
        // Including last Value
        ll option1 = value[n] + helperKnapsack(weight, value, n - 1, maxWeight - weight[n], dp);

        // Not Including last Value
        ll option2 = helperKnapsack(weight, value, n - 1, maxWeight, dp);

        ll ans = max(option1, option2);

        dp[n][maxWeight] = ans;
        return ans;
    }
    else
    {
        ll ans = helperKnapsack(weight, value, n - 1, maxWeight, dp);
        dp[n][maxWeight] = ans;
        return ans;
    }
}

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here

    ll **dp = new ll *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new ll[maxWeight + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = -1;
        }
    }

    ll ans = helperKnapsack(weight, value, n - 1, maxWeight, dp);

    ans = (int)ans;

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