/* Vanya has been studying all day long about sequences and other Complex Mathematical Terms.
She thinks she has now become really good at it.
So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her : 
Vanya has been given an integer array A of size N.
Now, she needs to find the number of increasing sub - sequences of this array with length ≥1 and GCD = 1. 
A sub - sequence of an array is obtained by deleting some(or none) elements and 
maintaining the relative order of the rest of the elements.
As the answer may be large, print it Modulo 10^9 + 7 She finds this task really easy, and thinks that you can do it too.Can you ? */

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll VanyaGCD(int n, int *arr)
{
    ll **dp = new ll *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new ll[101];

        for (int j = 0; j <= 100; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][arr[0]] = 1;
    ll sum = dp[0][1];

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                for (int g = 1; g <= 100; g++)
                {
                    int newGCD = __gcd(arr[i], g);
                    dp[i][newGCD] = (dp[i][newGCD] + dp[j][g]) % MOD;
                }
            }
        }

        dp[i][arr[i]]++;
        sum = (sum + dp[i][1]) % MOD;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return sum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << VanyaGCD(n, arr) << endl;

    delete[] arr;

    return 0;
}
