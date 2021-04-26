#include <iostream>

using namespace std;

int flipSpecificBit(int n, int i)
{
    n = n ^ (1 << i);
    return n;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << flipSpecificBit(n, i) << endl;

    return 0;
}
