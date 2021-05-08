/* Given an integer N, 
find and return the count of unique Binary search trees(BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10 ^ 9 + 7. */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int countBSTsRecursive(int n, long long *dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    long long total = 0;

    if (dp[n] > 0)
    {
        return dp[n];
    }

    for (int k = 1; k <= n; k++)
    {
        long long ansLeft = countBSTsRecursive(k - 1, dp);
        dp[k - 1] = ansLeft;

        long long ansRight = countBSTsRecursive(n - k, dp);
        dp[n - k] = ansRight;

        total += (ansLeft * ansRight);
        total = total % MOD;
    }

    int ans = (int)total;
    return ans;
}

int countBSTsIterative(int n)
{
    long long *dp = new long long[n + 1]{};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[i - j - 1] * dp[j];
            dp[i] = dp[i] % MOD;
        }
    }

    int ans = (int)dp[n];

    delete dp;

    return ans;
}

int countBST(int n)
{
    // long long *dp = new long long[n + 1]{};

    // Recursive
    // return countBSTsRecursive(n, dp);
    // delete dp;

    //Iterative
    return countBSTsIterative(n);
}

int main()
{
    int n;
    cin >> n;
    cout << countBST(n) << endl;

    return 0;
}
