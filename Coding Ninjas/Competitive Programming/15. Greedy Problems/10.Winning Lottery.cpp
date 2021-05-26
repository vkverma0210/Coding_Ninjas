/* Harshit knows by his resources that this time the winning lottery number 
is the smallest number whose sum of the digits is S and the number of digits is D.
You have to help Harshit and print the winning lottery number. */

#include <bits/stdc++.h>

using namespace std;

void winningLottery(int s, int d, int *digits)
{
    digits[0] = 1;
    s -= 1;
    int i = d - 1;

    while (i >= 0)
    {
        if (i == 0)
        {
            digits[i] += s;
        }
        if (s > 9)
        {
            digits[i] = 9;
            s -= 9;
        }
        else if (s <= 9)
        {
            digits[i] += s;
            s = 0;
        }
        i--;
    }
}

int main()
{
    int s, d;
    cin >> s >> d;

    int *digits = new int[d]{};

    winningLottery(s, d, digits);

    for (int i = 0; i < d; i++)
    {
        cout << digits[i];
    }
    cout << endl;

    delete[] digits;
    return 0;
}