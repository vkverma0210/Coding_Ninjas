/* For a given integer array/list of size N, 
find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list 
when the following two conditions are met.
A pair (arr[i], arr[j]) is said to be an inversion when,
1. arr[i] > arr[j] 
2. i < j

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N). */

#include <iostream>

using namespace std;

long long merge(long long *arr, int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int temp[right - left + 1];

    long long count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    return count;
}

long long merge_sort(long long *arr, int left, int right)
{
    long long count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;

        long long countLeft = merge_sort(arr, left, mid);
        long long countRight = merge_sort(arr, mid + 1, right);
        long long myCount = merge(arr, left, mid + 1, right);
        return myCount + countLeft + countRight;
    }

    return count;
}

long long getInversions(long long *arr, int n)
{
    //Write your code here

    long long ans = merge_sort(arr, 0, n - 1);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    long long *arr = new long long[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n) << endl;

    delete arr;

    return 0;
}