/* A cube free number is a number who’s none of the divisor is a cube number(A cube number is a cube of a integer like 8(2 * 2 * 2), 27(3 * 3 * 3)).
So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc(we will consider 1 as cube free).
8, 16, 24, 27, 32 etc are not cube free number.
So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. 
Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers. */

#include <bits/stdc++.h>

using namespace std;

void create_sieve(int *sieve)
{
    for (int i = 0; i < 1000001; i++)
    {
        sieve[i] = 0;
    }

    sieve[0] = -1;

    for (int i = 2; i <= 100; i++)
    {
        for (int j = i * i * i; j < 1000001; j += i * i * i)
        {
            sieve[j] = -1;
        }
    }

    int k = 1;

    for (int i = 1; i <= 1000000; i++)
    {
        if (sieve[i] != -1)
        {
            sieve[i] = k;
            k++;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    int *sieve = new int[1000001];
    create_sieve(sieve);

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        if (sieve[n] != -1)
        {
            cout << "Case " << i + 1 << ": " << sieve[n] << "\n";
        }
        else
        {
            cout << "Case " << i + 1 << ": "
                 << "Not Cube Free\n";
        }
    }

    return 0;
}