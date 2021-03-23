/* You have been given an integer array/list(ARR) of size N. 
Where N is equal to [2M + 1].
Now, in the given array/list, 
'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list. */

#include <bits/stdc++.h>

using namespace std;

/*
int findUnique(int *arr, int n)
{
    // Write your code here

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }

    for (auto x : um)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }
}
*/

int findUnique(int *arr, int n)
{
    // Write your code here

    int Xor = 0;

    for (int i = 0; i < n; i++)
    {
        Xor ^= arr[i];
    }

    return Xor;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}