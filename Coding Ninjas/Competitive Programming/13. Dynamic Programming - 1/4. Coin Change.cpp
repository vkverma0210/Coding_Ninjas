#include <bits/stdc++.h>

using namespace std;

int coin_change(int n, int *d, int numD)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    if (numD == 0)
    {
        return 0;
    }

    int first = coin_change(n - d[0], d, numD);
    int second = coin_change(n, d + 1, numD - 1);
    return first + second;
}

int main()
{
    int d[2] = {1, 2};
    cout << coin_change(4, d, 2) << endl;
}