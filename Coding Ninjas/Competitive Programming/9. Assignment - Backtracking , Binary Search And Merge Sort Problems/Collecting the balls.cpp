/* There are ‘n’ number of balls in a container. 
Mr. Sharma and Singh want to take balls out from the container. 
At each step, Mr. Sharma took ‘k’ balls out of the box and 
Mr. Singh took one-tenth of the remaining balls. 
Suppose there are 29 balls at the moment and k=4. 
Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). 
If there are less than ‘k’ balls remaining at some moment, 
then Mr. Sharma will take all the balls which will get the container empty. 
The process will last until the container becomes empty. 
Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool process(ll n, ll mid)
{
    ll x = n;
    ll sum = 0;

    while (n > 0 && n >= mid)
    {
        sum += mid;
        n = n - mid;
        n = n - (n / 10);
    }

    sum += n;

    if (2 * sum >= x)
    {
        return true;
    }

    return false;
}

int main()
{
    ll n;
    cin >> n;

    ll minval = 1;
    ll maxval = n;

    ll finalMin = INT_MAX;

    while (minval <= maxval)
    {
        ll mid = (minval + maxval) / 2;
        if (process(n, mid))
        {
            maxval = mid - 1;
            finalMin = mid;
        }
        else
        {
            minval = mid + 1;
        }
    }

    cout << finalMin << endl;

    return 0;
}
