/* You are given a set of N integers.
You have to return true if there exists a subset that sum up to K, otherwise return false. */

#include <iostream>

using namespace std;

// Iterative Extended
bool isSubsetPresentIterativeExtend(int *arr, int n, int sum)
{
    //Write your code here
    bool **dp = new bool *[2];
    for (int i = 0; i <= 1; i++)
    {
        dp[i] = new bool[sum + 1];
    }

    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    dp[0][0] = true;

    int flag = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[flag][j] = dp[flag ^ 1][j];

            if (j >= arr[i - 1])
            {
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - arr[i - 1]];
            }
        }
        flag = flag ^ 1;
    }

    bool ans = dp[flag ^ 1][sum];

    for (int i = 0; i <= 2; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

// Iterative
bool isSubsetPresentIterative(int *arr, int n, int sum)
{
    //Write your code here
    bool **dp = new bool *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new bool[sum + 1];
    }

    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    bool ans = dp[n][sum];

    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

bool helperSubsetSum(int *arr, int n, int sum, int **dp)
{
    if (sum == 0)
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }

    if (dp[n][sum] >= 0)
    {
        return (dp[n][sum] == 1);
    }

    bool ans;
    if (arr[0] <= sum)
    {
        bool option1 = helperSubsetSum(arr + 1, n - 1, sum, dp);
        bool option2 = helperSubsetSum(arr + 1, n - 1, sum - arr[0], dp);

        if (option1 || option2)
        {
            ans = 1;
        }
    }
    else
    {
        ans = (int)helperSubsetSum(arr + 1, n - 1, sum, dp);
    }

    dp[n][sum] = ans;

    return (ans == 1);
}

//Recursive
bool isSubsetPresent(int *arr, int n, int sum)
{
    //Write your code here

    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    bool ans = helperSubsetSum(arr, n, sum, dp);

    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}

int main()
{
    int n, sum;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    // if (isSubsetPresentIterative(arr, n, sum))
    // {
    //     cout << "Yes";
    // }
    // else
    // {
    //     cout << "No";
    // }

    // if (isSubsetPresentIterativeExtend(arr, n, sum))
    // {
    //     cout << "Yes";
    // }
    // else
    // {
    //     cout << "No";
    // }

    if (isSubsetPresent(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete[] arr;
}