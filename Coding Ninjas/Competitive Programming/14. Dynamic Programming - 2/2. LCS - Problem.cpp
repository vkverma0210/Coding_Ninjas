/* Given two strings, S and T with lengths M and N, 
find the length of the 'Longest Common Subsequence'.

For a string 'str'(per se) of length K, 
the subsequences are the strings containing characters in the same relative order as they are present in 'str,' 
but not necessarily contiguous. 
Subsequences contain all the strings of length varying from 0 to K. */

#include <iostream>
#include <cstring>

using namespace std;

int lcs(string s, string t)
{
	int m = s.length();
	int n = t.length();

	int **dp = new int *[m + 1];
	for (int i = 0; i <= m; i++)
	{
		dp[i] = new int[n + 1];
	}

	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[m - i] == t[m - j])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int ans = dp[m][n];

	for (int i = 0; i <= m; i++)
	{
		delete[] dp[i];
	}

	delete[] dp;

	return ans;
}

int main()
{
	string s;
	string t;

	cin >> s;
	cin >> t;

	cout << lcs(s, t) << endl;
}