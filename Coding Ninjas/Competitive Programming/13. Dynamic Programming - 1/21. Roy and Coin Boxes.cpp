/* Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and 
adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    int start[n + 1]{};
    int end[n + 1]{};
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        start[a]++;
        end[b]++;
    }

    int freq[n + 1]{};

    for (int i = 1; i <= n; i++)
    {
        freq[i] = start[i] - end[i - 1] + freq[i - 1];
    }

    int freqCount[n + 1]{};
    for (int i = 1; i <= n; i++)
    {
        freqCount[freq[i]]++;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        freqCount[i] += freqCount[i + 1];
    }

    int query;
    cin >> query;

    while (query--)
    {
        int q;
        cin >> q;
        cout << freqCount[q] << endl;
    }

    return 0;
}
