/* For the given infinite supply of coins of each of denominations, 
D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, 
in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible. */

#include <iostream>
#include <algorithm>

using namespace std;

int changeCount(int *denominations, int numDenominations, int value, int **storage)
{
    if (value == 0)
    {
        return 1;
    }

    if (numDenominations == 0)
    {
        return 0;
    }

    if (value < 0)
    {
        return 0;
    }

    if (storage[numDenominations][value] > -1)
    {
        return storage[numDenominations][value];
    }

    int first = changeCount(denominations, numDenominations, value - denominations[0], storage);
    int second = changeCount(denominations + 1, numDenominations - 1, value, storage);
    storage[numDenominations][value] = first + second;

    return first + second;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    //Write your code here
    sort(denominations, denominations + numDenominations);

    int **storage = new int *[numDenominations + 1];
    for (int i = 0; i < numDenominations + 1; i++)
    {
        storage[i] = new int[value + 1];
        for (int j = 0; j < value + 1; j++)
        {
            storage[i][j] = -1;
        }
    }

    int ans = changeCount(denominations, numDenominations, value, storage);

    for (int i = 0; i < numDenominations + 1; i++)
    {
        delete storage[i];
    }

    delete storage;

    return ans;
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}