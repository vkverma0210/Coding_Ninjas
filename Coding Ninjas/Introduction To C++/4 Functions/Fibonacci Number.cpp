/* Given a number N, figure out if it is a member of fibonacci series or not. 
Return true if the number is member of fibonacci series else false.
Fibonacci Series is defined by the recurrence
    F(n) = F(n-1) + F(n-2)
where F(0) = 0 and F(1) = 1  */

#include <iostream>

using namespace std;

bool checkMember(int n)
{
    int temp = 0, a = 0, b = 1;
    bool check = true;

    while (temp <= n)
    {
        if (temp == n)
            return true;
        temp = a + b;
        a = b;
        b = temp;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    if (checkMember(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
