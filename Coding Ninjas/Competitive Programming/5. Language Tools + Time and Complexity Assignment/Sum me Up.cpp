/* There will be ‘t’ test cases having an integer. You have to sum up all the digits of this integer. 
For e.g. For 6754, the answer will be 6 + 7 + 5 + 4 = 22. */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // Using string for greater number
        /*
        string s;
        cin >> s;

        long ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            ans += s[i] - 48;
        }

        cout << ans << endl;
        */

        // Using long 
        long n;
        cin >> n;
        long sum = 0;
        while(n != 0)
        {
            sum += n % 10;
            n /= 10;
        }

        cout << sum << endl;
    }

    return 0;
}