//Largest Sum Contiguous Subarray

#include <iostream>

using namespace std;

int kadane_Algorithm(int arr[], int size)
{
    int max_so_far = arr[0], curr_max = arr[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << kadane_Algorithm(arr, n) << endl;
    delete[] arr;

    return 0;
}