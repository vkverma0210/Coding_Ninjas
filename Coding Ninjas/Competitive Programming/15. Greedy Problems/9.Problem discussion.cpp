/* Harshit gave Aahad an array of size N and 
asked to minimize the difference between the maximum value and minimum value 
by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help */

#include <bits/stdc++.h>

using namespace std;

int getMinDifference(int n, int k, int *arr)
{
    if (n == 1)
    {
        return 0;
    }

    sort(arr, arr + n);

    int ans = arr[n - 1] - arr[0];
    int small = arr[0] + k;
    int big = arr[n - 1] - k;

    if (small > big)
    {
        swap(small, big);
    }

    for (int i = 1; i < n - 1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        if (subtract >= small || add <= big)
        {
            continue;
        }

        if (big - subtract <= add - small)
        {
            small = subtract;
        }
        else
        {
            big = add;
        }
    }

    return min(ans, big - small);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getMinDifference(n, k, arr) << endl;

    delete[] arr;

    return 0;
}