/* Vova again tries to play some computer card game.
The rules of deck creation in this game are simple.
Vova is given an existing deck of n cards and a magic number k.
The order of the cards in the deck is fixed.
Each card has a number written on it;
number ai is written on the i - th card in the deck.

After receiving the deck and the magic number, 
Vova removes x(possibly x = 0) cards from the top of the deck, 
y(possibly y = 0) cards from the bottom of the deck, 
and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards).
So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck. 

Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. 
So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, 
how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid? */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll *a = new ll[n + 1];

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<ll, ll>> kp;

    ll bakup_k = k;

    for (ll i = 2; i * i <= bakup_k; i++)
    {
        if ((bakup_k % i) == 0)
        {
            ll count = 0;

            while (bakup_k % i == 0)
            {
                bakup_k /= i;
                count++;
            }

            kp.push_back({i, count});
        }
    }

    if (bakup_k != 1)
    {
        kp.push_back({bakup_k, 1});
    }

    vector<pair<ll, ll>> ep = kp;

    for (ll i = 0; i < ep.size(); i++)
    {
        ep[i].second = 0;
    }

    ll ans = 0;

    ll j = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll x = 0; x < ep.size(); x++)
        {
            if (a[i] % ep[x].first == 0)
            {
                ll f = ep[x].first;

                ll num = a[i];
                ll count = 0;

                while (num % f == 0)
                {
                    num /= f;
                    count++;
                }

                ep[x].second += count;
            }
        }

        while (j <= i)
        {
            ll flag = 0;

            for (ll x = 0; x < kp.size(); x++)
            {
                if (ep[x].second < kp[x].second)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                ans += n - i;

                for (ll x = 0; x < ep.size(); x++)
                {
                    if (a[j] % ep[x].first == 0)
                    {
                        ll f = ep[x].first;
                        ll num = a[j];
                        ll count = 0;

                        while (num % f == 0)
                        {
                            num /= f;
                            count++;
                        }
                        ep[x].second -= count;
                    }
                }
            }
            else
            {
                break;
            }
            j++;
        }
    }

    cout << ans << "\n";

    return 0;
}