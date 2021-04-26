/* You are given two integers N and i.
You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left. */

#include <iostream>

using namespace std;

int turnOffIthBit(int n, int i)
{
    n = n & ~(1 << i);
    return n;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << turnOffIthBit(n, i) << endl;

    return 0;
}
