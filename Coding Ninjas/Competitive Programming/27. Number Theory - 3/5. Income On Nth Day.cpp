/* Daulat Ram is an affluent business man.
After demonetization, IT raid was held at his accommodation in which all his money was seized.
He is very eager to gain his money back, he started investing in certain ventures and earned out of them.
On the first day, his income was Rs.X, followed by Rs.Y on the second day.
Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was 
FN = FN - 1 + FN - 2 + FN - 1×FN - 2 

Given his income on day 0 and day 1, calculate his income on the Nth day(yeah Its that simple). */

#include <bits/stdc++.h>

using namespace std;

#define m 1000000006
#define m1 1000000007

typedef long long int ll;

void multiply(ll A[2][2], ll M[2][2])
{
    ll first = ((A[0][0] % m) * (M[0][0] % m) + (A[0][1] % m) * (M[1][0] % m)) % m;
    ll second = ((A[0][0] % m) * (M[0][1] % m) + (A[0][1] % m) * (M[1][1] % m)) % m;
    ll third = ((A[1][0] % m) * (M[0][0] % m) + (A[1][1] % m) * (M[1][0] % m)) % m;
    ll fourth = ((A[1][0] % m) * (M[0][1] % m) + (A[1][1] % m) * (M[1][1] % m)) % m;

    A[0][0] = first;
    A[0][1] = second;
    A[1][0] = third;
    A[1][1] = fourth;
}

void power(ll A[2][2], ll n)
{
    if (n == 1)
    {
        return;
    }

    power(A, n / 2);

    multiply(A, A);

    if (n % 2 != 0)
    {
        ll M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

ll fib(ll n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    ll A[2][2] = {{1, 1}, {1, 0}};

    power(A, n - 1);

    return A[0][0];
}

ll powerModular(ll a, ll x)
{
    if (x == 0)
    {
        return 1;
    }

    if (x % 2 == 0)
    {
        return powerModular((a * a) % m1, x / 2);
    }
    else
    {
        return ((a % m1) * powerModular((a * a) % m1, (x - 1) / 2) % m1) % m1;
    }
}

int main()
{
    ll t, f0, f1, n;
    cin >> t;

    while (t--)
    {
        ll f0, f1, n;
        cin >> f0 >> f1 >> n;

        if (n == 0)
        {
            cout << f0 << "\n";
        }
        else if (n == 1)
        {
            cout << f1 << "\n";
        }
        else
        {
            ll fibn_m1 = fib(n - 1) % m;

            ll fibn = fib(n) % m;

            ll one = powerModular(f0 + 1, fibn_m1) % m1;
            ll two = powerModular(f1 + 1, fibn) % m1;
            ll ansfinal = ((one % m1) * (two % m1)) % m1;

            ansfinal = (ansfinal - 1 + m1) % m1;

            cout << ansfinal << "\n";
        }
    }

    return 0;
}