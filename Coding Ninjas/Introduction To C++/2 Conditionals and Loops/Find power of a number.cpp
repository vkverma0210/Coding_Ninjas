/* Write a program to find x to the power n (i.e. x^n). 
Take x and n from the user. You need to print the answer.  */

#include <iostream>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    long ans = 1;

    if (n == 0)
    {
        ans = 1;
    }
    while (n--)
    {
        ans *= x;
    }

    cout << ans << endl;

    return 0;
}
