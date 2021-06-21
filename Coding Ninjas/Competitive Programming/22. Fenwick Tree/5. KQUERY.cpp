/* Given a sequence of n numbers a1, a2, ..., an and a number of k - queries.
A k - query is a triple(i, j, k)(1 ≤ i ≤ j ≤ n).
For each k - query(i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai + 1, ..., aj. */

#include <bits/stdc++.h>

using namespace std;

int query(int index, int *BIT, int n)
{
    int count = 0;

    for (; index > 0; index -= index & (-index))
    {
        count += BIT[index];
    }

    return count;
}

void update(int index, int *BIT, int n)
{
    for (; index <= n; index += index & (-index))
    {
        BIT[index]++;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;

    vector<pair<pair<int, int>, pair<int, int>>> events;

    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;

        events.push_back({{k, i}, {l, r}});
    }

    sort(events.begin(), events.end(), greater<pair<pair<int, int>, pair<int, int>>>());

    int *BIT = new int[30002]{};
    int *ans = new int[200002]{};

    for (int i = 0; i < q; i++)
    {
        int l, r, index, k;
        l = events[i].second.first;
        r = events[i].second.second;
        k = events[i].first.first;
        index = events[i].first.second;

        for (int j = arr.size() - 1; j >= 0; j--)
        {
            if (arr[j].first > k)
            {
                update(arr[j].second, BIT, n);

                arr.pop_back();
            }
            else
            {
                break;
            }
        }

        ans[index] = query(r, BIT, n) - query(l - 1, BIT, n);
    }

    for (int i = 1; i <= events.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
