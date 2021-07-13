/* Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. 
Aman, their friend has been helping them out. 
But as it goes, Sameer and Arpit have got bored of problems involving factorials. 
Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. 
So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. 
He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. 
He asks T such queries. */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll modularExp(ll a, ll b, ll c)
{
    if (a == 0)
    {
        return 0;
    }

    if (b == 0)
    {
        return 1;
    }

    ll ans;

    if (b % 2 == 0)
    {
        ll smallAns = modularExp(a, b / 2, c);
        ans = (smallAns * smallAns) % c;
    }
    else
    {
        ll smallAns = modularExp(a, b - 1, c);
        ans = a % c;
        ans = (ans * smallAns) % c;
    }

    return ans;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, p;
        cin >> n >> p;

        if (n >= p)
        {
            cout << 0 << "\n";
            continue;
        }

        ll fact = 1;

        for (ll i = n + 1; i <= p - 1; i++)
        {
            fact = (fact * i) % p;

            if (fact == 0)
            {
                break;
            }
        }

        ll ans = modularExp(fact, p - 2, p);

        cout << p - ans << "\n";
    }

    return 0;
}