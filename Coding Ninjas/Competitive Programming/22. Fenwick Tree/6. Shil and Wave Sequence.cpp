/* Given a sequence A1, A2, A3..AN of length N.
Find total number of wave subsequences having length greater than 1. 

Wave subsequence of sequence A1, A2, A3..AN is defined as a set of integers i1, i2..ik such that Ai1<Ai2> Ai3<Ai4....or Ai1> Ai2<Ai3> Ai4....and i1 < i2 < ... < ik.
Two subsequences i1, i2..ik and j1, j2..jm are considered different if k != m or there exists some index l such that il ! = jl */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mod 1000000007

int query(int index, int **BIT, int type, int n)
{
    int count = 0;

    for (; index > 0; index -= index & (-index))
    {
        count = (count + BIT[index][type]) % mod;
    }

    return count;
}

void update(int index, int **BIT, int type, int val, int n)
{
    for (; index <= 100001; index += index & (-index))
    {
        BIT[index][type] = (BIT[index][type] + val) % mod;
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n + 1]{};
    int maxtill = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        maxtill = max(maxtill, arr[i]);
    }

    int **BIT = new int *[100001];
    for (int i = 0; i <= 100000; i++)
    {
        BIT[i] = new int[3]{};
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int el = arr[i];

        int a = (query(el - 1, BIT, 0, n) + query(el - 1, BIT, 2, n)) % mod;

        int b = (query(maxtill, BIT, 1, n) - query(el, BIT, 1, n) + query(maxtill, BIT, 2, n) - query(el, BIT, 2, n)) % mod;

        update(el, BIT, 0, b, n);
        update(el, BIT, 1, a, n);
        update(el, BIT, 2, 1, n);

        a = (a + mod) % mod;
        b = (b + mod) % mod;
        ans = (ans + a) % mod;
        ans = (ans + b) % mod;
    }

    cout << ans << "\n";

    return 0;
}