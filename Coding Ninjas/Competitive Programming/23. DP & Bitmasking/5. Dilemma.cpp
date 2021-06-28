/* Abhishek, a blind man recently bought N binary strings all of equal length.
A binary string only contains '0' s and '1' s.
The strings are numbered from 1 to N and all are distinct, 
but Abhishek can only differentiate between these strings by touching them.
In one touch Abhishek can identify one character at a position of a string from the set.
Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int find_touches(int pos, int mask, vector<string> &v, int **dp)
{
    if ((mask & (mask - 1)) == 0)
    {
        return 0;
    }

    if (pos < 0)
    {
        return 10000;
    }

    if (dp[pos][mask] != INT_MAX)
    {
        return dp[pos][mask];
    }

    int newMask1 = 0;
    int newMask2 = 0;
    int touches = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (mask & (1 << i))
        {
            touches++;

            if (v[i][pos] == '0')
            {
                newMask1 |= 1 << i;
            }
            else
            {
                newMask2 |= 1 << i;
            }
        }
    }

    int ans1 = find_touches(pos - 1, newMask1, v, dp) + find_touches(pos - 1, newMask2, v, dp) + touches;
    int ans2 = find_touches(pos - 1, mask, v, dp);

    int ans = min(ans1, ans2);
    dp[pos][mask] = ans;
    return ans;
}

int minimumTouchesRequired(int n, vector<string> v)
{
    int **dp = new int *[v[0].size()];

    for (int i = 0; i < v[0].size(); i++)
    {
        dp[i] = new int[1 << (n + 1)];

        for (int j = 0; j < (1 << (n + 1)); j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    return find_touches(v[0].size() - 1, (1 << n) - 1, v, dp);
}

int main()
{
    int n;

    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
    }
    cout << minimumTouchesRequired(n, v) << endl;
}