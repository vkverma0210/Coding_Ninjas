/*  Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long ans = 0;
    long pv = 1;
    while (n != 0)
    {
        int curr = n % 2;
        ans = ans + curr * pv;
        pv *= 10;
        n /= 2;
    }
    cout << ans << endl;

    return 0;
}
