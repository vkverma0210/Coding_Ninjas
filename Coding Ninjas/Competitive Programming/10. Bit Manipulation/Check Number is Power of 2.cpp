#include <iostream>

using namespace std;

bool checkPower(int n)
{
    if (n < 0)
        return false;

    if ((n & (n - 1)) == 0)
        return true;
    return false;
}

int main()
{
    int n;

    cin >> n;

    bool ans = checkPower(n);

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
