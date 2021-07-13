/*Varun is learning method of successive squaring so that he can calculate a ^ b mod m quickly.
To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister.
His sister converted each b into base 3. 
Varun wrote everything in base 10. 
Help Varun to do his excercise. */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int power(ll a, string b, int m)
{
    int len = b.length();
    ll final_ans = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (b[i] == '0')
        {
            a %= m;
            a = (((a * a) % m) * a) % m;
        }

        if (b[i] == '1')
        {
            final_ans = final_ans * a;
            final_ans %= m;
            a = (((a * a) % m) * a) % m;
        }

        if (b[i] == '2')
        {
            final_ans = ((final_ans * a) % m) * a;
            final_ans %= m;
            a = (((a * a) % m) * a) % m;
        }
    }

    return final_ans;
}
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll a;
        string b;
        int m;
        cin >> a >> b >> m;

        cout << power(a, b, m) << endl;
    }

    return 0;
}