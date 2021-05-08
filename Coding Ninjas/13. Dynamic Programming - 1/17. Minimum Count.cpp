/* Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1 ^ 2 + 1 ^ 2 + 1 ^ 2 + 1 ^ 2} and {2 ^ 2}.
The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares. */

#include <bits/stdc++.h>

using namespace std;

int minCountRecursive(int n, int *dp)
{
    if (ceil(sqrt(n)) == sqrt(n))
    {
        return 1;
    }

    if (n <= 3)
    {
        return n;
    }

    if (dp[n] > 0)
    {
        return dp[n];
    }

    int count = n;
    for (int i = 1; i <= n; i++)
    {
        int sq = i * i;
        if (sq > n)
        {
            break;
        }

        count = min(count, 1 + minCountRecursive(n - sq, dp));
    }

    dp[n] = count;
    return count;
}

int minCountIterative(int n, int *dp)
{
    if (ceil(sqrt(n)) == sqrt(n))
    {
        return 1;
    }

    if (n <= 3)
    {
        return n;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        int count = i;
        for (int j = 1; j <= i; j++)
        {
            int sq = j * j;
            if (sq > i)
            {
                break;
            }

            count = min(count, 1 + dp[i - sq]);
        }

        dp[i] = count;
    }

    return dp[n];
}

int minCount(int n)
{
    int *dp = new int[n + 1]{};

    //Recursive
    // int ans = minCountRecursive(n, dp);

    //Iterative
    int ans = minCountIterative(n, dp);

    delete[] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}