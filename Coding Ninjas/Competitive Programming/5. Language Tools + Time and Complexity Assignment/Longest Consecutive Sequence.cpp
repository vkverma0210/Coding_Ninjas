/* You are given an array of unique integers that contain numbers in random order. 
You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. 
If the length of the longest possible sequence is one, 
then the output array must contain only single element. */

#include <bits/stdc++.h>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if (s.find(arr[i] - 1) == s.end())
        {
            int j = 1;
            temp.push_back(arr[i]);
            cout << arr[i] << endl;
            while (s.find(arr[i] + j) != s.end())
            {
                temp.push_back(arr[i] + j);
                j++;
            }

            if (temp.size() > ans.size())
            {
                ans = temp;
            }
        }
    }

    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1)
    {
        cout << " " << ans[ans.size() - 1] << endl;
    }

    delete[] arr;
}