/*  You are given S a sequence of n integers i.e. S = s1, s2, ..., sn. 
Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn 
(0 <= i <= n) in such a way that the first part is strictly decreasing 
while the second is strictly increasing one.  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev;
    cin >> prev;

    int count = 2, current;
    bool isDec = true;
    while (count <= n)
    {
        cin >> current;
        if (current == prev)
        {
            cout << "false";
            break;
        }
        count++;
        if (current < prev)
        {
            if (isDec == false)
            {
                cout << "false";
                return 0;
            }
        }
        else
        {
            if (isDec == true)
            {
                isDec = false;
            }
        }
        prev = current;
    }

    cout << "true";

    return 0;
}