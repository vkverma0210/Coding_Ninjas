/* World is getting more evil and it's getting tougher to get into the Evil League of Evil. 
Since the legendary Bad Horse has retired, 
now you have to correctly answer the evil questions of Dr. Horrible,
who has a PhD in horribleness (but not in Computer Science). 
You are given an array of N elements, which are initially all 0. \

After that you will be given C commands. 
They are - 
0 p q v - you have to add v to all numbers in the range of p to q(inclusive), 
where p and q are two indexes of the array.

1 p q- output a line containing a single integer which is the sum of all the array elements between p and q(inclusive) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void update(ll *tree, ll *lazy, ll s, ll e, ll i, ll l, ll r, ll value)
{
    if (s > e)
    {
        return;
    }

    if (lazy[i] != 0)
    {
        tree[i] += (e - s + 1) * lazy[i];

        if (s != e)
        {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (l > e || r < s)
    {
        return;
    }

    if (s >= l && e <= r)
    {
        tree[i] += (e - s + 1) * value;

        if (s != e)
        {
            lazy[2 * i] += value;
            lazy[2 * i + 1] += value;
        }

        lazy[i] = 0;
        return;
    }

    ll mid = (s + e) / 2;

    update(tree, lazy, s, mid, 2 * i, l, r, value);
    update(tree, lazy, mid + 1, e, 2 * i + 1, l, r, value);

    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

ll query(ll *tree, ll *lazy, ll s, ll e, ll i, ll l, ll r)
{
    if (s > e)
    {
        return 0;
    }

    if (lazy[i] != 0)
    {
        tree[i] += (e - s + 1) * lazy[i];
        if (s != e)
        {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (l > e || r < s)
    {
        return 0;
    }

    if (s >= l && e <= r)
    {
        return tree[i];
    }

    ll mid = (s + e) / 2;
    ll left = query(tree, lazy, s, mid, 2 * i, l, r);
    ll right = query(tree, lazy, mid + 1, e, 2 * i + 1, l, r);

    return left + right;
}

void display(ll n, ll *tree)
{
    for (ll i = 0; i < n; i++)
    {
        cout << tree[i] << endl;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, c;
        cin >> n >> c;

        ll *tree = new ll[3 * n]{};
        ll *lazy = new ll[3 * n]{};

        while (c--)
        {
            ll qtype;
            cin >> qtype;

            if (qtype == 0)
            {
                ll p, q, value;
                cin >> p >> q >> value;
                update(tree, lazy, 1, n, 1, p, q, value);
                // display(n, tree);
            }
            else
            {
                ll p, q;
                cin >> p >> q;
                ll ans = query(tree, lazy, 1, n, 1, p, q);
                cout << ans << endl;
            }
        }
    }

    return 0;
}