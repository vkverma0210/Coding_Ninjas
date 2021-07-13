/* There are only three phases in Swaps life : Sleep, Play and Study.
Also, there are two types of emotions Swaps experiences : Happy and Sad.
Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad.
Quite obvious, isn 't it? But we know that life isn' t that great, one cannot be happy all the time.

Swaps, being a very sensitive guy, doesn't like to mix his emotions in a particular day. 
So each day, he is in exactly one of the three phases. 
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, 
can you tell him in how many ways can he achieve this ? 
Since the output value can be very large, take modulo with 1000000007(10 ^ 9 + 7) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 1000001
#define MOD 1000000007

ll modExpo(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;

    ll fact[MAX];
    fact[0] = 1;

    for (ll i = 1; i < MAX; i++)
    {
        fact[i] = i * fact[i - 1];

        if (fact[i] >= MOD)
        {
            fact[i] %= MOD;
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << "\n";
            continue;
        }

        ll ans = modExpo(2, k);
        ans = (ans * fact[n]) % MOD;
        ans = (ans * modExpo(fact[k], MOD - 2)) % MOD;
        ans = (ans * modExpo(fact[n - k], MOD - 2)) % MOD;
        cout << ans << endl;
    }

    return 0;
}