/* She needs your help. 
The problem is they don’t have chairs in reception. 
They are ordering chairs from NinjasKart. 
They don’t want to order more than required. 
You have to tell the minimum number of chairs required such that none of the customers has to stand. */

#include <bits/stdc++.h>

using namespace std;

int comman_Interval(int start[], int end[], int n)
{
    int ans = 0, count = 0;

    sort(start, start + n);
    sort(end, end + n);

    for (int i = 0; i < n; i++)
    {
        cout << start[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << end[i] << " ";
    }

    cout << endl;

    int i = 0, j = 0, m = n;

    while (i < m && j < n)
    {
        if (start[i] < end[j])
        {
            count++;
            ans = max(ans, count);
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }

    return ans;
}

int main()
{
    // Write your code here

    int n;
    cin >> n;

    int start[n];
    int end[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    cout << comman_Interval(start, end, n) << endl;

    return 0;
}