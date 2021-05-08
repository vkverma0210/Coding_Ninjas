/* Given a 2D array, find the maximum sum rectangle in it.
In other words find maximum sum over all rectangles in the matrix. */

#include <bits/stdc++.h>

using namespace std;

int kadane(int *temp, int m)
{
    int best_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < m; i++)
    {
        curr_sum += temp[i];

        if (curr_sum > best_sum)
        {
            best_sum = curr_sum;
        }

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }

    return best_sum;
}

int MaximumRectSum(int **rectangle, int n, int m)
{
    int maxSum = INT_MIN;
    for (int left = 0; left < m; left++)
    {
        int *temp = new int[n]();
        for (int right = left; right < m; right++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] += rectangle[i][right];
            }
            maxSum = max(maxSum, kadane(temp, n));
        }
    }

    return maxSum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int **rectangle = new int *[n];

    for (int i = 0; i < n; ++i)
    {
        rectangle[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> rectangle[i][j];
        }
    }

    cout << MaximumRectSum(rectangle, n, m) << "\n";

    for (int i = 0; i < n; ++i)
    {
        delete[] rectangle[i];
    }

    delete[] rectangle;

    return 0;
}
