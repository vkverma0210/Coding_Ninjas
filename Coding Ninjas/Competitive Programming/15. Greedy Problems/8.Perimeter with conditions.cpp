/* Aahad gives an array of integers and asks Harshit to find which three elements form a triangle(non - degenerate).
The task seems easy to Harshit.
So, Aahad adds some conditions to this task - 
1. Find the triangle with maximum perimeter 
2. If there are two or more combinations with same value of maximum perimeter, 
then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    // Write your code here
    ll n;
    cin >> n;

    ll *sides = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sides[i];
    }

    sort(sides, sides + n, greater<ll>());

    ll ans = 0;
    ll a, b, c;

    for (int i = 0; i < n - 2; i++)
    {
        a = sides[i];
        b = sides[i + 1];
        c = sides[i + 2];

        if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
        {
            ans = 1;
            break;
        }
    }

    if (ans == 1)
    {
        cout << c << " " << b << " " << a << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}