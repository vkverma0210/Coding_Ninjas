/* Write a program that asks the user for a number N and a choice C. 
And then give them the possibility to choose between computing the sum 
and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;

    int sum = 0, product = 1;
    if (c == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << sum << endl;
    }
    else if (c == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            product *= i;
        }
        cout << product << endl;
    }

    else
    {
        cout << -1 << endl;
    }

    return 0;
}