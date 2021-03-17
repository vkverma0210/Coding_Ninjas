/* Ayush loves the characters ‘a’, ‘s’, and ‘p’. 
He got a string of lowercase letters and 
he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. 
Help him find it out. */

#include <bits/stdc++.h>
using namespace std;

void occurance(char str[], int n)
{
    int ac = 0, sc = 0, pc = 0;

    for (int i = 0; i < n; i++)
    {
        switch (str[i])
        {
        case 'a':
            ac++;
            break;
        case 's':
            sc++;
            break;
        case 'p':
            pc++;
            break;
        }
    }

    cout << ac << " " << sc << " " << pc;
}

int main()
{
    int n;
    cin >> n;

    char s[n];
    cin >> s;

    occurance(s, n);
    cout << endl;
    return 0;
}
