/* Given an integer n.
Initially you have permutation p of size n : p[i] = i.
To build new array a from p following steps are done while permutation p is not empty : 
Choose maximum existing element in p and define it as x;
Choose all such y in p that gcd(x, y) ≠ 1;
Add all chosen numbers into array a in decreasing order and remove them from permutation.
Your task is to find a after p became empty.

Note : gcd(a, b) is the greatest common divisor of integers a and b. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll *sieve = new ll[n + 2]{};

    for (ll i = 0; i <= n; i++)
    {
        sieve[i] = i;
    }

    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; i * j <= n; j++)
        {
            ll el_ = i * j;

            if (sieve[el_] == el_)
            {
                sieve[el_] = i;
            }
        }
    }

    ll *mark = new ll[n + 2]{};

    for (ll i = n; i >= 1; i--)
    {
        vector<ll> v;
        ll lpd = sieve[i]; // lowest prime divisor

        if (mark[i] == 0)
        {
            ll n_bakup = i;
            v.push_back(n_bakup);
            mark[n_bakup] = 1;

            while (n_bakup != 1)
            {
                ll n_temp = i;

                while (n_temp != lpd)
                {
                    n_temp -= lpd;

                    if (mark[n_temp] == 0)
                    {
                        mark[n_temp] = 1;
                        v.push_back(n_temp);
                    }
                }

                while (n_bakup % lpd == 0)
                {
                    n_bakup /= lpd;
                }

                lpd = sieve[n_bakup];
            }
        }

        sort(v.begin(), v.end(), greater<ll>());

        for (ll i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }

    delete sieve;
    delete mark;

    return 0;
}