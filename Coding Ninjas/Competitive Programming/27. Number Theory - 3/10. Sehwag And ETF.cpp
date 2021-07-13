/* Sehwag has been solving a lot of mathematical problems recently.
He was learning ETF(Euler Totient Function) and found the topic quite interesting.
So, he tried solving a question on ETF.
He will be given two numbers L and R.
He has to find the probability that the ETF of a number in the range[L, R] is divisible by a number K. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 1100001

int main()
{
    ll t;
    cin >> t;
    
    bool primes[MAX];

    for (ll i = 3; i < MAX; i += 2)
    {
        primes[i] = 1;
    }

    primes[2] = 1;

    for (ll i = 3; i * i < MAX; i += 2)
    {
        if (primes[i])
        {
            for (ll j = i * i; j < MAX; j += 2 * i)
            {
                primes[j] = 0;
            }
        }
    }

    ll p[300001];
    p[0] = 2;
    ll c = 1;

    for (ll i = 3; i < MAX; i += 2)
    {
        if (primes[i])
        {
            p[c++] = i;
        }
    }

    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;

        if (k == 1)
        {
            cout << fixed;
            cout << setprecision(6) << 1 << endl;
            continue;
        }

        ll phi[MAX], num[MAX];

        for (ll i = a; i <= b; i++)
        {
            phi[i - a] = i;
            num[i - a] = i;
        }

        ll base;

        for (ll i = 0; p[i] * p[i] <= b; i++)
        {
            base = a / p[i] * p[i];

            while (base < a)
            {
                base += p[i];
            }

            while (base < p[i])
            {
                base += p[i];
            }

            if (base == p[i])
            {
                base += p[i];
            }

            for (ll j = base; j <= b; j += p[i])
            {
                while (num[j - a] % p[i] == 0)
                {
                    num[j - a] /= p[i];
                }

                phi[j - a] -= phi[j - a] / p[i];
            }
        }

        for (ll i = a; i <= b; i++)
        {
            if (num[i - a] > 1)
            {
                phi[i - a] -= phi[i - a] / num[i - a];
            }

            num[i - a] = 1;
        }

        ll c = 0;

        for (ll i = a; i <= b; i++)
        {
            if (phi[i - a] % k == 0)
            {
                c++;
            }
        }

        double ans = c;
        ans /= (b - a + 1);
        std::cout << fixed;
        std::cout << setprecision(6) << ans << endl;
    }

    return 0;
}