/* For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
which counts the number of times a 1 bit is adjacent to another 1 bit. 
For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. 
For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int dp[101][101][2];

ll adjBitCounts(int n, int k, int x)
{
    if (dp[n][k][x] >= 0)
    {
        return dp[n][k][x];
    }

    if (n == 1)
    {
        if (k == 0)
        {
            dp[n][k][x] = 1;
            return 1;
        }

        dp[n][k][x] = 0;
        return 0;
    }

    if (k < 0)
    {
        dp[n][k][x] = 0;
        return 0;
    }

    if (x == 1)
    {
        ll ans1 = adjBitCounts(n - 1, k - 1, 1);
        ll ans2 = adjBitCounts(n - 1, k, 0);
        dp[n][k][x] = (ans1 + ans2) % MOD;
    }

    if (x == 0)
    {
        ll ans1 = adjBitCounts(n - 1, k, 1);
        ll ans2 = adjBitCounts(n - 1, k, 0);
        dp[n][k][x] = (ans1 + ans2) % MOD;
    }

    return dp[n][k][x];
}

ll bitCounts(int n, int k)
{
    ll ans1 = adjBitCounts(n, k, 1) % MOD;
    ll ans2 = adjBitCounts(n, k, 0) % MOD;
    ll ans = (ans1 + ans2) % MOD;

    return ans;
}

int main()
{
    int p;
    cin >> p;
    while (p--)
    {
        int data, n, k;
        cin >> data >> n >> k;

        for (int i = 0; i <= 101; i++)
        {
            for (int j = 0; j <= 101; j++)
            {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        ll ans = bitCounts(n, k);

        cout << data << " " << ans << endl;
    }

    return 0;
}
