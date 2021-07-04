/* You are given array a consisting of n distinct integers.
A set s of numbers is called good if you can rearrange the elements in such a way that 
each element divides the next element in the order, i.e.'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.

Find out number of distinct good sets that you can create using the values of the array.
You can use one value only once in a particular set;
ie. a set cannot have duplicate values.
Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.

As the answer could be large, print your answer modulo 10 ^ 9 + 7. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

int main()
{
    ll t;
    cin >> t;

    ll maxRange = 750001;

    int *sieve = new int[maxRange];

    while (t--)
    {
        for (ll i = 0; i < maxRange; i++)
        {
            sieve[i] = 0;
        }

        ll n;
        cin >> n;

        int *a = new int[n + 1];

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        for (ll i = 0; i < n; i++)
        {
            sieve[a[i]] = 1;
        }

        for (ll i = 1; i < maxRange; i++)
        {
            if (sieve[i] != 0)
            {
                for (ll j = 2; j * i < maxRange; j++)
                {
                    if (sieve[i * j] != 0)
                    {
                        sieve[j * i] = (sieve[j * i] + sieve[i]) % mod;
                    }
                }
            }
        }

        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            count = (count + sieve[a[i]]) % mod;
        }

        cout << count << "\n";

        delete a;
    }

    delete sieve;

    return 0;
}