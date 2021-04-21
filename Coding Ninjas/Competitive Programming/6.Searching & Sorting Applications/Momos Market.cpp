/*Shreya loves to eat momos. 
Her mother gives her money to buy vegetables but she manages to save some money out of it daily. 
After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. 
Each of the shops of momos has a rate per momo. 
She visits the market and starts buying momos (one from each shop) starting from the first shop. 
She will visit the market for ‘q’ days. 
You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. 
She cannot use the remaining money of one day on some other day. 
But she will save them for other expenses in the future, 
so, you also need to tell the sum of money left with her at the end of each day. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll *arr, ll n, ll mid, ll money)
{
    if (arr[mid] <= money)
    {
        return true;
    }

    return false;
}

void findMomos(ll *arr, ll n, ll money)
{
    ll start = 0;
    ll end = n - 1;
    ll mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (check(arr, n, mid, money))
        {
            start = mid;
        }
        else
        {
            end = mid;
        }

        if (end - start == 1)
        {
            if (check(arr, n, end, money))
            {
                cout << end + 1 << " " << money - arr[end] << endl;
                return;
            }
            else
            {
                if (!check(arr, n, start, money))
                {
                    cout << 0 << " " << money << endl;
                    return;
                }

                cout << start + 1 << " " << money - arr[start] << endl;
                return;
            }
        }
    }

    cout << mid + 1 << " " << money - arr[mid] << endl;
}

int main()
{
    ll n;
    cin >> n;

    ll *price = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    ll q;
    cin >> q;

    ll *moneyLeft = new ll[q];
    for (int i = 0; i < q; i++)
    {
        cin >> moneyLeft[i];
    }

    ll *prefix_sum_price = new ll[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += price[i];
        prefix_sum_price[i] = sum;
    }

    for (ll i = 0; i < q; i++)
    {
        findMomos(prefix_sum_price, n, moneyLeft[i]);
    }

    return 0;
}
