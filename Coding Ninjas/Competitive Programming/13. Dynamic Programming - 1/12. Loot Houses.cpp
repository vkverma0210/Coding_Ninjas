/* A thief wants to loot houses.
He knows the amount of money in each house.
He cannot loot two consecutive houses.
Find the maximum amount of money he can loot. */

#include <iostream>

using namespace std;

#define MOD 1000000007

//Recursively
int getAnsRecursive(int *arr, int n, int i, int *storage)
{
    if (i >= n)
    {
        return 0;
    }

    if (storage[i] != -1)
    {
        return storage[i];
    }

    int possibleAns1 = (arr[i] + getAnsRecursive(arr, n, i + 2, storage)) % MOD;
    int possibleAns2 = getAnsRecursive(arr, n, i + 1, storage) % MOD;
    int ans = max(possibleAns1, possibleAns2);
    storage[i] = ans;

    return ans;
}

// Iteratively
int getAnsIterative(int *arr, int n, int i, int *storage)
{
    storage[0] = arr[0];
    storage[1] = max(arr[0], arr[1]);

    int maxSum = 0;

    for (int i = 2; i < n; i++)
    {
        int ans = max(arr[i] + storage[i - 2], storage[i - 1]);
        storage[i] = ans;
        maxSum = ans;
    }

    return maxSum;
}

int maxMoneyLooted(int *arr, int n)
{
    //Write your code here
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    int *storage = new int[n];

    for (int i = 0; i < n; i++)
    {
        storage[i] = -1;
    }

    //Recursively
    // int ans = getAnsRecursive(arr, n, 0, storage);

    // Iteratively
    int ans = getAnsIterative(arr, n, 0, storage);

    delete storage;
    return ans;
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}