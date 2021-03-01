#include <iostream>

using namespace std;

bool is_Sorted2(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool isSmallerOutput = is_Sorted2(a + 1, size - 1);

    if (!isSmallerOutput)
    {
        return false;
    }

    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool is_sorted(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (a[0] > a[1])
    {
        return false;
    }

    bool isSmallerSorted = is_sorted(a + 1, size - 1);
    return isSmallerSorted;
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

    cout << is_sorted(arr, n) << endl;

    cout << is_Sorted2(arr, n) << endl;

    delete[] arr;

    return 0;
}