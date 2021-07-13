/* Given the value of N, you will have to find the value of G.
The meaning of G is given in the following code

G = 0;
for (i = 1; i < N; i++)
    for (j = i + 1; j <= N; j++)
        G += gcd(i, j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers. */

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
typedef long long int ll;

int main()
{
    ll arr[MAX];
    arr[1] = 1;

    for (ll i = 2; i < MAX; i += 2)
    {
        arr[i] = i / 2;
    }

    for (ll i = 3; i < MAX; i += 2)
    {
        if (!arr[i])
        {
            arr[i] = i - 1;

            for (ll j = i << 1; j < MAX; j += i)
            {
                if (!arr[j])
                {
                    arr[j] = j;
                }

                arr[j] = arr[j] / i * (i - 1);
            }
        }
    }

    ll S[MAX], G[MAX];

    for (ll i = 0; i < MAX; i++)
    {
        S[i] = arr[i];
    }

    for (ll i = 2; i < MAX; i++)
    {
        for (ll j = 2; j * i < MAX; j++)
        {
            S[i * j] += j * arr[i];
        }
    }

    G[1] = 0;

    for (ll i = 2; i < MAX; i++)
    {
        G[i] = G[i - 1] + S[i];
    }

    while (1)
    {
        ll n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        cout << G[n] << "\n";
    }

    return 0;
}