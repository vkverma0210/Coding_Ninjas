/* Given a string, count the number of distinct subsequences of it(including empty subsequence).
For the uninformed, A subsequence of a string is a new string which is formed from the original string 
by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not . */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll allSubsequence(string s)
{
    int len = s.length();

    ll *dp = new ll[len + 1];

    ll *prevIndex = new ll[26];
    for (int i = 0; i < 26; i++)
    {
        prevIndex[i] = -1;
    }

    dp[0] = 1;

    for (ll i = 1; i <= len; i++)
    {
        dp[i] = (dp[i - 1] * 2) % MOD;

        if (prevIndex[s[i - 1] - 65] != -1)
        {
            dp[i] = (dp[i] - dp[prevIndex[s[i - 1] - 65] - 1] + MOD) % MOD;
        }

        prevIndex[s[i - 1] - 65] = i;
    }

    ll ans = dp[len] % MOD;
    delete[] dp;
    delete[] prevIndex;

    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << allSubsequence(s) << endl;
    }

    return 0;
}
