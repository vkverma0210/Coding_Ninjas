/* Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, 
FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance? */

#include <bits/stdc++.h>

using namespace std;

bool check(long long mid, long long stalls[], int n, int c)
{
    int cows = 1;
    long long last_position = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_position >= mid)
        {
            last_position = stalls[i];
            cows++;

            if (cows == c)
                return true;
        }
    }

    return false;
}

int cowsProblem(long long stalls[], int n, int c)
{
    sort(stalls, stalls + n);

    long long start = 0;
    long long end = stalls[n - 1] - stalls[0];
    long long ans = -1;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (check(mid, stalls, n, c))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    // Write your code here
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        long long stalls[n];

        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }

        long long ans = cowsProblem(stalls, n, c);

        cout << ans << endl;
    }
}