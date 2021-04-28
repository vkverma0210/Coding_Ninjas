#include <bits/stdc++.h>

using namespace std;

int balancedBTs(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int m = pow(10, 9) + 7;
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);

    long long res1 = (long long)x * x;
    long long res2 = (long long)x * y * 2;

    int ans1 = (int)(res1 % m);
    int ans2 = (int)(res2 % m);

    int ans = (ans1 + ans2) % m;

    return ans;
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;

    return 0;
}