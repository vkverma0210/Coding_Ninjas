/* Given a sequence of N(1 ≤ N ≤ 10, 000) integers S1, ..., SN(0 ≤ Si < 100, 000), 
compute the number of increasing subsequences of S with length K(1 ≤ K ≤ 50 and K ≤ N);
that is, the number of K - tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK. */

#include <bits/stdc++.h>

using namespace std;

#define mod 5000000

int query(int **BIT, int index, int bitval)
{
    int count = 0;

    for (; index > 0; index -= index & (-index))
    {
        count = (count + BIT[bitval][index]) % mod;
    }

    return count;
}

void update(int **BIT, int index, int bitval, int val, int n)
{
    for (; index <= n; index += index & (-index))
    {
        BIT[bitval][index] = (BIT[bitval][index] + val) % mod;
    }
}

void compress_values(int *a, int n)
{
    int *b = new int[n + 1]{};

    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);

    map<int, int> m;
    int k = 1;

    for (int i = 1; i <= n; i++)
    {
        if (m.find(b[i]) == m.end())
        {
            m[b[i]] = k++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = m[a[i]];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    int *a = new int[n + 1]{};

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    compress_values(a, n);

    int **BIT = new int *[52];

    for (int i = 0; i <= 51; i++)
    {
        BIT[i] = new int[300001]{};
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int x;

            if (j == 1)
            {
                x = 1;
            }
            else
            {
                x = query(BIT, a[i] - 1, j - 1);
            }

            update(BIT, a[i], j, x, n);

            if (j == k)
            {
                ans = (ans + x) % mod;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}