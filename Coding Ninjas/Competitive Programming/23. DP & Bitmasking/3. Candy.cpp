/* Gary is a teacher at XYZ school.
To reward his N students he bought a packet of N candies all with different flavours.
But the problem is some students like certain flavour while some doesn't. 
Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes. */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 16
typedef long long ll;

ll solve_helper(int like[][MAXN], int N, ll *dp, int p, int mask)
{
    if (p >= N)
    {
        return 1;
    }

    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    ll ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (!(mask & (1 << i)) && like[p][i] == 1)
        {
            ans += solve_helper(like, N, dp, p + 1, mask | (1 << i));
        }
    }

    dp[mask] = ans;

    return ans;
}

long long solve(int like[][MAXN], int N)
{
    ll *dp = new ll[1 << N];

    for (int i = 0; i < (1 << N); i++)
    {
        dp[i] = -1;
    }

    return solve_helper(like, N, dp, 0, 0);
}

int main()
{
    int n, like[MAXN][MAXN];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> like[i][j];
        }
    }

    cout << solve(like, n) << endl;

    return 0;
}