/*Given a number N, print sum of all even numbers from 1 to N.*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    while (n >= 2)
    {
        if (n % 2 == 0)
        {
            sum += n;
        }
        n--;
    }

    cout << sum << endl;

    return 0;
}