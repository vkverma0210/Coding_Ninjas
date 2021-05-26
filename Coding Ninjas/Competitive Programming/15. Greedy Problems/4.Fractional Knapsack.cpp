/* You are given weights and values of N items.
You have to select and put these selected items in a knapsack of capacity W.
Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.

Note : You are allowed to break the items in parts. */

#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value, weight;
};

bool compare(struct Item a, struct Item b)
{
    double value1 = ((double)a.value) / (a.weight);
    double value2 = ((double)b.value) / (b.weight);

    return value1 > value2;
}

double fKnapsack(int n, int W, struct Item arr[])
{
    sort(arr, arr + n, compare);

    int currW = 0;
    double fValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (currW + arr[i].weight <= W)
        {
            currW += arr[i].weight;
            fValue += arr[i].value;
        }
        else
        {
            int rWeight = W - currW;
            fValue += arr[i].value * ((double)rWeight / arr[i].weight);
            break;
        }
    }

    return fValue;
}

int main()
{
    // write your code here

    int n, W;
    cin >> n >> W;

    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << fixed << setprecision(6) << fKnapsack(n, W, arr) << endl;

    return 0;
}