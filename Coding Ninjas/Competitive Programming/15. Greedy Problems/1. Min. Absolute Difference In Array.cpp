/* Given an integer array A of size N, 
find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj(where i != j) is | ai - aj |. */

#include <iostream>
#include <algorithm>

using namespace std;

int minAbsoluteDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int min = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] < min)
        {
            min = arr[i + 1] - arr[i];
        }
    }

    return min;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << minAbsoluteDiff(input, size) << endl;

    return 0;
}
