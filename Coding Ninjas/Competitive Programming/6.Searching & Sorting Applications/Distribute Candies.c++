/* Shaky has N(1 <= N <= 50000) candy boxes each of them contains a non - zero number of candies(between 1 and 1000000000).
Shaky want to distibute these candies among his K(1 <= K <= 1000000000) IIIT - Delhi students.
He want to distibute them in a way such that : 
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible.
Help Shaky in finding out what is the maximum number of candies which a student can get. */

#include <bits/stdc++.h>

using namespace std;

bool check(long long arr[], int n, int mid, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] / mid;
        if (sum >= k)
        {
            return true;
        }
    }

    return false;
}

int distributeCandy(long long arr[], int n, int k)
{
    sort(arr, arr + n);

    int start = 0;
    int end = arr[n - 1];
    int mid = 0;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (check(arr, n, mid, k))
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
        if (end - start == 1)
        {
            if (check(arr, n, end, k))
            {
                return end;
            }
            else
            {
                return start;
            }
        }
    }

    return mid;
}

int main()
{

    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        long long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << distributeCandy(arr, n, k) << endl;
    }
}