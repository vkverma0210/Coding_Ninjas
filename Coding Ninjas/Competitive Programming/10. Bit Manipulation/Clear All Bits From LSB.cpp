#include <iostream>

using namespace std;

int RemoveAllBitsFromLSB(int n, int i)
{
    int m = ~((1 << (i + 1)) - 1);
    return n & m;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << RemoveAllBitsFromLSB(n, i) << endl;

    return 0;
}