/* Mike is a stock trader and makes a profit by buying and selling stocks. 
He buys a stock at a lower price and sells it at a higher price to book a profit. 
He has come to know the stock prices of a particular stock for n upcoming days in future and 
wants to calculate the maximum profit by doing the right transactions 
(single transaction = buying + selling). 
Can you help him maximize his profit?

Note: A transaction starts after the previous transaction has ended. 
Two transactions can't overlap or run in parallel.

The stock prices are given in the form of an array A for n days.

Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions. */

#include <bits/stdc++.h>

using namespace std;

int maxProfit(int n, int k, int *prices, int curr_i, int ongoing, int ***dp)
{
    if (curr_i == n || k == 0)
    {
        return 0;
    }

    if (dp[curr_i][k][ongoing] != -1)
    {
        return dp[curr_i][k][ongoing];
    }

    int option1 = maxProfit(n, k, prices, curr_i + 1, ongoing, dp);

    int option2 = INT_MIN;
    if (ongoing == 1)
    {
        option2 = prices[curr_i] + maxProfit(n, k - 1, prices, curr_i + 1, 0, dp);
    }
    else
    {
        if (k > 0)
        {
            option2 = maxProfit(n, k, prices, curr_i + 1, 1, dp) - prices[curr_i];
        }
    }

    int ans = max(option1, option2);
    dp[curr_i][k][ongoing] = ans;
    return ans;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int k, n;
        cin >> k;
        cin >> n;
        int *prices = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        int ***dp = new int **[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[k + 1];
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = new int[2];
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        cout << maxProfit(n, k, prices, 0, 0, dp) << endl;

        for (int i = 0; i <= n; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
        delete[] prices;
    }

    return 0;
}
