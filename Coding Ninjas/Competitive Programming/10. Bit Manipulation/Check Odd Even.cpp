#include <iostream>

using namespace std;

bool checkOddEven(int n)
{
    if ((n & 1) == 0)
        return true;
    return false;
}

int main()
{
    int n;

    cin >> n;

    bool ans = checkOddEven(n);

    if (ans)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }

    return 0;
}
