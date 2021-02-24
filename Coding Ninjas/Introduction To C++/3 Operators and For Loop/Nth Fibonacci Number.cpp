/* Nth term of fibonacci series F(n) is calculated using following formula -
    F(n) = F(n-1) + F(n-2), 
    Where, F(1) = F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << c << endl;

    return 0;
}