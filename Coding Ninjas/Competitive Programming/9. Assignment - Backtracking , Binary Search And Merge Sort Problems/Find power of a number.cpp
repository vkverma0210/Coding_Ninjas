/* Write a program to find x to the power n(i.e.x ^ n).
Take x and n from the user.
You need to print the answer. */

#include <iostream>
using namespace std;

long power(int x, int n)
{
    if (x == 0 && n == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 1;
    }

    if (x == 0)
    {
        return 0;
    }

    return x * power(x, n - 1);
}

int main()
{
    // Write your code here
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;

    return 0;
}
