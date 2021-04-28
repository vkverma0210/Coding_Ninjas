/* Professor Jain has a class full of notorious students. 
To get anything done from them is a herculean task. 
Prof Jain wanted to organize a test. 
He gave this responsibility to Aahad. 
Aahad did an excellent job of organizing the test. 
As a reward, the professor gave him an sequence of numbers to play with. 
But Aahad likes playing with "interesting" sequence of numbers, 
which are sequences that have equal elements.
Now, the problem is - Prof Jain has a sequence with elements, 
and that sequence isn't always "interesting”. 
To ensure sequence has equal elements, Prof Jain has 2 options:
1) Choose two elements of sequence . 
DECREASE the first element by 1 and INCREASE the second element by 1. 
This operation costs 'k' coins.
2) Choose one element of array and INCREASE it by 1. 
This operation costs 'l' coins.
What’s the minimum number of coins Prof Jain needs to turn his sequence into a “interesting" sequence for Aahad? */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, l;
    cin >> n >> k >> l;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int minele = INT_MAX, maxele = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxele)
        {
            maxele = arr[i];
        }

        if (arr[i] < minele)
        {
            minele = arr[i];
        }
    }

    int minCost = INT_MAX;

    for (int i = minele; i <= maxele; i++)
    {
        int currCost = 0;
        int noOfIncrease = 0;
        int noOfDecrease = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] < i)
            {
                noOfIncrease += i - arr[j];
            }

            else if (arr[j] > i)
            {
                noOfDecrease += arr[j] - i;
            }
        }

        if (noOfDecrease > noOfIncrease)
        {
            continue;
        }
        else
        {
            currCost = noOfDecrease * k + (noOfIncrease - noOfDecrease) * l;
            if (currCost < minCost)
            {
                minCost = currCost;
            }
        }
    }

    cout << minCost << endl;

    return 0;
}