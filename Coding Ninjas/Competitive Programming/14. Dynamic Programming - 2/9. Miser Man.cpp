/* Jack is a wise and miser man. Always tries to save his money.

One day, he wants to go from city A to city B. B
etween A and B, there are N number of cities(including B and excluding A) 
and in each city there are M buses numbered from 1 to M. 
And the fare of each bus is different. 
Means for all N*M busses, fare (K) may be different or same.

Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.

You are to help Jack t/o go from A to B by spending the minimum amount of money.
N, M, K <= 100. */

#include <bits/stdc++.h>

using namespace std;

int minFair(int n, int m, int bus[101][101], int dp[101][101], int curr_n, int curr_m)
{
    if (curr_n == n)
    {
        return 0;
    }

    if (dp[curr_n][curr_m] != -1)
    {
        return dp[curr_n][curr_m];
    }

    int option1 = minFair(n, m, bus, dp, curr_n + 1, curr_m);

    int option2 = INT_MAX;

    if (curr_m - 1 >= 0)
    {
        option2 = minFair(n, m, bus, dp, curr_n + 1, curr_m - 1);
    }

    int option3 = INT_MAX;

    if (curr_m + 1 < m)
    {
        option3 = minFair(n, m, bus, dp, curr_n + 1, curr_m + 1);
    }

    int ans = min(option1, min(option2, option3));

    dp[curr_n][curr_m] = bus[curr_n][curr_m] + ans;

    return dp[curr_n][curr_m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    int bus[101][101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> bus[i][j];
        }
    }

    int dp[101][101];
    memset(dp, -1, 101 * 101 * sizeof(int));
    int minVal = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        int min_current = minFair(n, m, bus, dp, 0, i);
        if (min_current < minVal)
        {
            minVal = min_current;
        }
    }

    cout << minVal << endl;

    return 0;
}
