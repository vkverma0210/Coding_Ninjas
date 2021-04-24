/* There is a company named James Peterson &Co.
The company has ‘n’ employees.
The employees have skills from 0 to n - 1. 
All the employees have distinct skills.
The manager of James Peterson &Co.wants to sort the employees on the basis of their skills in ascending order.
He is only allowed to swap two employees which are adjacent to each other.
He is given the skills of employees in an array of size ‘n’.
He can swap the skills as long as the absolute difference between their skills is 1. 
You need to help the manager out and tell whether it is possible to sort the skills of employees or not . */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] == arr[i] - 1)
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        int flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                flag = 1;
            }
        }

        string ans = flag == 1 ? "No" : "Yes";

        cout << ans << endl;
    }

    return 0;
}
