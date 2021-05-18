/* Gary has two string S and V.
Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note : The input data will be such that there will always be a solution. */

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll solveHelper(string s, string v, int **dp)
{
    int n = s.length();
    int m = v.length();

    if (n == 0)
    {
        return 10000;
    }

    if (m <= 0)
    {
        return 1;
    }

    if (dp[n][m] >= 0)
    {
        return dp[n][m];
    }

    ll option1 = solveHelper(s.substr(1), v, dp);

    int index = 0;

    for (index = 0; index < m; index++)
    {
        if (s[0] == v[index])
        {
            break;
        }
    }

    if (index == m && n - 1 == 0)
    {
        return 1;
    }

    if (index == m)
    {
        return 1;
    }

    ll option2 = 1 + solveHelper(s.substr(1), v.substr(index + 1), dp);

    ll ans = min(option1, option2);

    dp[n][m] = ans;

    return ans;
}

ll solve(string s, string v)
{
    // Write your code here
    int len1 = s.length();
    int len2 = v.length();

    int **dp = new int *[len1 + 1];
    for (int i = 0; i <= len1; i++)
    {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++)
        {
            dp[i][j] = -1;
        }
    }

    ll ans = solveHelper(s, v, dp);

    for (int i = 0; i <= len1; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}