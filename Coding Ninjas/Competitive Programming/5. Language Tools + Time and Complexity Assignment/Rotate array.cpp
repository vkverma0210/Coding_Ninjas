/* You have been given a random integer array/list(ARR) of size N. 
Write a function that rotates the given array/list by D elements(towards the left). */

#include <bits/stdc++.h>
using namespace std;

void reverse(int *input, int start, int end)
{
    while (start < end)
    {
        swap(input[start++], input[end--]);
    }
}

void rotate(int *input, int d, int n)
{
    if (n == 0)
    {
        return;
    }

    if (d >= n)
    {
        d = d % n;
    }

    reverse(input, 0, n - 1);
    reverse(input, 0, n - d - 1);
    reverse(input, n - d, n - 1);
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

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}