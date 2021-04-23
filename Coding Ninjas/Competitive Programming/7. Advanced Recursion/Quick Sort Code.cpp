/* Sort an array A using Quick Sort.
Change in the input array itself.So no need to return or print anything. */

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int input[], int start, int end)
{
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (input[i] <= input[start])
        {
            count++;
        }
    }

    swap(input[start], input[start + count]);

    for (int i = start, j = end; i < count + start && j > count + start;)
    {
        if (input[i] <= input[start + count])
        {
            i++;
        }
        else if (input[j] > input[start + count])
        {
            j--;
        }
        else
        {
            swap(input[i++], input[j--]);
        }
    }

    return count + start;
}

void quick_sort(int input[], int start, int end)
{
    if (start < end)
    {
        int c = partition(input, start, end);
        quick_sort(input, start, c - 1);
        quick_sort(input, c + 1, end);
    }
}

void quickSort(int input[], int size)
{
    quick_sort(input, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);

    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
