/* You are given an array of positive integers as input.
Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence.
A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same. */

#include <iostream>
#include <algorithm>

using namespace std;

int *LISfront(int *arr, int n)
{
    int *output = new int[n];
    output[0] = 1;

    for (int i = 1; i < n; i++)
    {
        output[i] = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                continue;
            }
            else
            {
                int possibleAns = output[j] + 1;
                if (possibleAns > output[i])
                {
                    output[i] = possibleAns;
                }
            }
        }
    }

    return output;
}

int *LISback(int *arr, int n)
{
    int *output = new int[n];
    output[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        output[i] = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                continue;
            }
            else
            {
                int possibleAns = output[j] + 1;
                if (possibleAns > output[i])
                {
                    output[i] = possibleAns;
                }
            }
        }
    }

    return output;
}

int longestBitonicSubarray(int *input, int n)
{
    int *LisBegin = LISfront(input, n);
    int *LisEnd = LISback(input, n);
    int maximum = 1;

    for (int i = 0; i < n; i++)
    {
        maximum = max(maximum, LisBegin[i] + LisEnd[i] - 1);
    }

    return maximum;
}

int main()
{
    int n, input[100000];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << longestBitonicSubarray(input, n);

    return 0;
}
