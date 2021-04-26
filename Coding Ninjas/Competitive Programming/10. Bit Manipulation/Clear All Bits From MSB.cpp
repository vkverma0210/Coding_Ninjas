/* You are given two integers N and i.
You need to clear all bits from MSB to ith bit(start i from right to left) and return the updated N.
Counting of bits starts from 0 from right to left. */

#include <iostream>

using namespace std;

int RemoveAllBitsFromLSB(int n, int i)
{
    int m = ((1 << i) - 1);
    return n & m;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << RemoveAllBitsFromLSB(n, i) << endl;

    return 0;
}