/* A number is called n - factorful if it has exactly n distinct prime factors.
Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, 
that are n - factorful.
We consider 1 to be 0 - factorful. */

#include <iostream>

using namespace std;

void makeSieve(int *isPrime, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        isPrime[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == 0)
        {
            for (int j = 1; j * i <= n; j++)
            {
                isPrime[j * i] += 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    int *arr = new int[1000001];
    int **table = new int *[11];

    for (int i = 0; i < 11; i++)
    {
        table[i] = new int[1000001];
    }

    makeSieve(arr, 1000001);

    for (int i = 0; i < 11; i++)
    {
        table[i][0] = 0;
        table[i][1] = 0;

        for (int j = 2; j < 1000001; j++)
        {
            if (i == arr[j])
            {
                table[i][j] = table[i][j - 1] + 1;
            }
            else
            {
                table[i][j] = table[i][j - 1];
            }
        }
    }

    for (int i = 1; i <= t; i++)
    {
        int a, b, n;
        cin >> a >> b >> n;

        if (a == 1 && n == 0)
        {
            cout << 1 << endl;
            continue;
        }

        cout << table[n][b] - table[n][a - 1] << endl;
    }

    return 0;
}