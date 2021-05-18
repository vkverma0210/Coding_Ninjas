/* You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.

What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?

Illustration

Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]

An improper bracket expression:
[[[][]]][]][[]]

There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.

Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output. */

#include <bits/stdc++.h>

using namespace std;

int findPosition(int o, int c, int n, bool *sb, int **dp)
{
    if (o == n && c == n)
    {
        return 1;
    }

    if (o > n || c > n)
    {
        return 0;
    }

    if (dp[o][c] != -1)
    {
        return dp[o][c];
    }

    int ans;

    if (o == c || sb[o + c] == true)
    {
        ans = findPosition(o + 1, c, n, sb, dp);
    }
    else if (o == n)
    {
        ans = findPosition(o, c + 1, n, sb, dp);
    }
    else
    {
        ans = findPosition(o + 1, c, n, sb, dp) + findPosition(o, c + 1, n, sb, dp);
    }

    dp[o][c] = ans;
    return ans;
}

int main()
{
    int d;
    cin >> d;
    while (d--)
    {
        int n, k;
        cin >> n >> k;

        bool *startBrac = new bool[(2 * n) + 1];
        for (int i = 0; i < k; i++)
        {
            int index;
            cin >> index;
            startBrac[index - 1] = true;
        }

        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << findPosition(0, 0, n, startBrac, dp) << endl;
    }

    return 0;
}
