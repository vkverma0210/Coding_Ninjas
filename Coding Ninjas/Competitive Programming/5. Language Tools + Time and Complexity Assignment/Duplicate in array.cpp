/* You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. 
That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these,
there is a single integer value that is present twice. 
You need to find and return that duplicate number present in the array. */

#include <bits/stdc++.h>

using namespace std;

int findDuplicate(int *arr, int n)
{
    int sum2n = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        sum2n += i;
    }

    int sumOfElements = 0;

    for (int i = 0; i < n; i++)
    {
        sumOfElements += arr[i];
    }

    return (sumOfElements - sum2n);
}

/*
int findDuplicate(int *arr, int n)
{
    //Write your code here
    vector<int> count(n, 0);
    int ans {};
    
    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    
    for(int i = 0; i < count.size(); i++)
    {
        if(count[i] >= 2)
        {
            ans = i;
            break;
        }
    }
    
    return ans;
}
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << findDuplicate(input, size) << endl;
    }

    return 0;
}