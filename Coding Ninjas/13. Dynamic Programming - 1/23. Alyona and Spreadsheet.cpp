/* During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. 
The table consists of n rows and m columns. 
By ai, j we will denote the integer located at the i-th row and the j-th column. 
We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.

Teacher gave Alyona k tasks. 
For each of the tasks two integers l and r are given and Alyona has to answer the following question: 
if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? 
Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help! */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    int **arr = new int *[n] {};

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    int **dp = new int *[n] {};
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i - 1][j] <= arr[i][j])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = i;
            }
        }
    }

    int rowMin[n]{};

    for (int i = 0; i < n; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] < minimum)
            {
                minimum = dp[i][j];
            }
        }
        rowMin[i] = minimum;
    }

    for (int i = 0; i < n; i++)
    {
        cout << rowMin[i] << " ";
    }

    cout << endl;

    int k;
    cin >> k;

    while (k--)
    {
        int l, r;
        cin >> l >> r;
        if (rowMin[r - 1] <= l - 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        delete dp[i];
    }

    delete[] arr;
    delete[] dp;

    return 0;
}
