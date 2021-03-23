/* Given a random integer array A of size N. 
Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well. */

#include <bits/stdc++.h>

using namespace std;

int pairSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }

    int twice_count = 0;

    for (int i = 0; i < n; i++)
    {
        twice_count += um[0 - arr[i]];

        if (0 - arr[i] == arr[i])
        {
            twice_count--;
        }
    }

    return twice_count / 2;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n) << endl;

    delete[] arr;

    return 0;
}