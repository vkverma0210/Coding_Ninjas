/* You are given two strings S and T of lengths M and N, respectively.
Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other.
In order to do so, you can perform the following three operations : 
1. Delete a character 
2. Replace a character with another one 
3. Insert a character 

Note : Strings don't contain spaces in between. */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int editDistance(string s1, string s2)
{
    //Write your code here
    int m = s1.length();
    int n = s2.length();

    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
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
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}