/* Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. 
There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. 
A plane crew consists of two pilots - a captain and his assistant. 
A captain must be older than his assistant. 
Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. 
A captain's salary is larger than assistant's for the same pilot. 
However, it is possible that an assistant has larger salary than his captain. 
Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries 
if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews. */

#include <bits/stdc++.h>

using namespace std;

int minAmount(int n, int *a, int *c, int x, int **dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }

    int ans;

    if (x == 0)
    {
        ans = a[0] + minAmount(n - 1, a + 1, c + 1, 1, dp);
    }
    else if (x == n)
    {
        ans = c[0] + minAmount(n - 1, a + 1, c + 1, x - 1, dp);
    }
    else
    {
        int option1 = a[0] + minAmount(n - 1, a + 1, c + 1, x + 1, dp);
        int option2 = c[0] + minAmount(n - 1, a + 1, c + 1, x - 1, dp);
        ans = min(option1, option2);
    }

    dp[n][x] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n + 1];

    int *c = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];

        cin >> a[i];
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

    cout << minAmount(n, a, c, 0, dp) << endl;

    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;
    delete[] a;
    delete[] c;

    return 0;
}
