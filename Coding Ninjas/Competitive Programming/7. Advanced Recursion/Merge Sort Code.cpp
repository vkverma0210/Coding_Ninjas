/* Sort an array A using Merge Sort.Change in the input array itself.
So no need to return or print anything */

#include <iostream>

using namespace std;

void merge(int input[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
        {
            temp[k++] = input[i++];
        }
        else
        {
            temp[k++] = input[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = input[i++];
    }

    while (j <= end)
    {
        temp[k++] = input[j++];
    }

    for (int i = start, j = 0; i <= end; i++, j++)
    {
        input[i] = temp[j];
    }

    return;
}

void merge_Sort(int input[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_Sort(input, start, mid);
        merge_Sort(input, mid + 1, end);
        merge(input, start, mid, end);
    }
    return;
}

void mergeSort(int input[], int n)
{
    merge_Sort(input, 0, n - 1);
}

int main()
{
    int length;
    cin >> length;

    int *input = new int[length];

    for (int i = 0; i < length; i++)
        cin >> input[i];

    mergeSort(input, length);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}