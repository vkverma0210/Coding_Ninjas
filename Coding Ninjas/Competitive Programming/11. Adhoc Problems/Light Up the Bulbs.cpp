/* A bulb can be ‘ON’ or ‘OFF’.
Mr.Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’.
Their status is represented in a string of size ‘n’ consisting of 0’s and 1’s, 
where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ represent the bulb is ‘ON’.
Mr.Navdeep has been given the task to light up all the bulbs.
He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it.
E.g. “0 110 001” -> “0 011 001”.Substring(1, 3) is reversed here.
This operation will cost him Rs. ‘X’.
Second, chose any segment of bulbs and reverse their present condition.
i.e.if the bulb is ‘ON’, make it ‘OFF’ and if it is ‘OFF’, make it ‘ON’.
E.g. “0 011 001” -> “0 100 001”.
Substring(1, 3) is complemented.This operation will cost him Rs. ‘Y’.
You need to help Mr.Navdeep that how much minimum amount it will require to make all the bulbs lightened.
(or make all the characters as ‘1’ in the representation string) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    if (n == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    ll group = 0;
    if (s[0] == '0')
    {
        group++;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
        {
            group++;
        }
    }

    if (group == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    cout << (group - 1) * min(x, y) + y << endl;

    return 0;
}
