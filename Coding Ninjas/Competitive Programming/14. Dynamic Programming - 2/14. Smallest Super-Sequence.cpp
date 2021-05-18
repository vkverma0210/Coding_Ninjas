/* Given two strings S and T with lengths M and N.
Find and return the length of their shortest 'Super Sequence'.
The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.

Note : If the two strings do not have any common characters, then return the sum of the lengths of the two strings. */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int smallestSequence(string str1, string str2, int len1, int len2, int c1, int c2, int **dp)
{
    if (c1 == len1 && c2 == len2)
    {
        return 0;
    }

    if (dp[c1][c2] != -1)
    {
        return dp[c1][c2];
    }

    int ans;

    if (c1 == len1)
    {
        ans = len2 - c2;
    }

    else if (c2 == len2)
    {
        ans = len1 - c1;
    }
    else
    {
        if (str1[c1] == str2[c2])
        {
            ans = 1 + smallestSequence(str1, str2, len1, len2, c1 + 1, c2 + 1, dp);
        }
        else
        {
            ans = 1 + min(smallestSequence(str1, str2, len1, len2, c1 + 1, c2, dp), smallestSequence(str1, str2, len1, len2, c1, c2 + 1, dp));
        }
    }

    dp[c1][c2] = ans;

    return ans;
}

int smallestSuperSequence(string str1, string str2)
{
    //Write your code here
    int len1 = str1.length();
    int len2 = str2.length();

    int **dp = new int *[len1 + 1];
    for (int i = 0; i <= len1; i++)
    {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = smallestSequence(str1, str2, len1, len2, 0, 0, dp);

    for (int i = 0; i <= len1; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);

    return 0;
}