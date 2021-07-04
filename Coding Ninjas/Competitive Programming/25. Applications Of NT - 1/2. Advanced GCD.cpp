/* Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers.
Then Sanchit implements the algorithm 

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit. */

#include <bits/stdc++.h>

using namespace std;

int findMod(string a, int b)
{
    int mod = 0;

    for (int i = 0; i < a.length(); i++)
    {
        int curr_num = int(a[i] - '0');

        mod = (mod * 10 + curr_num) % b;
    }

    return mod;
}

int find_gcd(int a, int b)
{
    if (a < b)
    {
        return find_gcd(b, a);
    }

    if (b == 0)
    {
        return a;
    }

    return find_gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int b;
        string a;
        cin >> b >> a;

        if (b == 0)
        {
            cout << a << "\n";
            continue;
        }

        int ans = findMod(a, b);

        cout << find_gcd(b, ans) << endl;
    }

    return 0;
}