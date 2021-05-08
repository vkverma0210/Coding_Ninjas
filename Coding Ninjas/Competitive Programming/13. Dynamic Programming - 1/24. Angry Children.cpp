/* Bill Gates is on one of his philanthropic journeys to a village in Utopia.
He has N packets of candies and would like to distribute one packet to each of the K children in the village
(each packet may contain different number of candies).
To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.

Suppose the K packets have(x1, x2, x3, ....xk) candies in them, where xi denotes the number of candies in the ith packet, 
then we define unfairness as unfairness = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        unfairness += abs(xi - xj)
                  
abs(x) denotes absolute value of x. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll k;
    cin >> k;

    ll *arr = new ll[n]{};

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll *dp = new ll[n]{};

    ll sum = 0;

    dp[0] = 0;

    sum += arr[0];

    for (ll i = 1; i < k; i++)
    {
        dp[i] = dp[i - 1] + i * arr[i] - sum;
        sum += arr[i];
    }

    ll min_unfairness = dp[k - 1];

    ll deleteElement = 0;

    for (ll i = k; i < n; i++)
    {
        sum -= arr[deleteElement];
        dp[i] = dp[i - 1] - 2 * (sum) + (k - 1) * arr[deleteElement] + (k - 1) * arr[i];
        sum += arr[i];
        deleteElement++;

        if (dp[i] < min_unfairness)
        {
            min_unfairness = dp[i];
        }
    }

    cout << min_unfairness << endl;

    delete[] arr;

    return 0;
}
