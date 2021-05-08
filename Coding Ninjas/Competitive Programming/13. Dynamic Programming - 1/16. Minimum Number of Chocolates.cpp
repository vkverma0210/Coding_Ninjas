/*Miss.Noor Rashid is a teacher.
She wants to give some chocolates to the students in her class.
All the students sit in a line, and each of them has a score according to performance.
Noor wants to give at least one chocolate to each student.
She distributes chocolates to them such that 
If two students sit next to each other,
then the one with the higher score must get more chocolates.
Miss.Noor wants to save money, 
so she wants to minimize the total number of chocolates.

Note : When two students have an equal score, 
they are allowed to have a different number of chocolates. */

#include <iostream>
#include <stdio.h>
using namespace std;

int getMin(int *arr, int n)
{
    //Write your code here
    if (n == 0 || n == 1)
    {
        return n;
    }

    int *dp = new int[n];

    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }

    int totalChocolates = 0;

    for (int i = 0; i < n; i++)
    {
        totalChocolates += dp[i];
    }

    delete[] dp;
    return totalChocolates;
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

    cout << getMin(arr, n);

    delete[] arr;
}