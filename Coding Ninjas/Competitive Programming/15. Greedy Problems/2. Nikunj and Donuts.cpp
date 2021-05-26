/* Nikunj loves donuts, but he also likes to stay fit. 
He eats n donuts in one sitting, and each donut has a calorie count, ci. 
After eating a donut with k calories, he must walk at least 2^j x k
(where j is the number donuts he has already eaten) miles to maintain his weight.

Given the individual calorie counts for each of the n donuts, 
find and print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight. 
Note that he can eat the donuts in any order. */

#include <bits/stdc++.h>

using namespace std;

long minimumDistance(int *arr, int n)
{
    sort(arr, arr + n, greater<int>());
    long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += arr[i] * pow(2, i);
    }

    return ans;
}

int main()
{
    //Write your code here

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long ans = minimumDistance(arr, n);

    cout << ans << endl;

    delete[] arr;

    return 0;
}