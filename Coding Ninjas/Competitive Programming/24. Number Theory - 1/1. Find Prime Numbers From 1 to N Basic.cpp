/* Given a number N, find number of primes in the range[1, N]. */

#include <iostream>

using namespace std;

bool checkPrime(int n)
{
    int countFactor = 0;

    for (int j = 1; j * j <= n; j++)
    {
        if ((n % j) == 0)
        {
            if (j * j == n)
            {
                countFactor += 1;
            }
            else
            {
                countFactor += 2;
            }
        }
    }

    if (countFactor == 2)
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (checkPrime(i))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}