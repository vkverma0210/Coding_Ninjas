/*You have been given a random integer array/list(ARR) of size N, and an integer X.
You need to search for the integer X in the given array/list using 'Linear Search'.*/

#include <iostream>

using namespace std;

int linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int x;
        cin >> x;

        int ans = linearSearch(arr, n, x);

        cout << ans << endl;
    }

    return 0;
}