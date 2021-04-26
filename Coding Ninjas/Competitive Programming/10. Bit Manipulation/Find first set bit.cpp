/* You are given an integer N.
You need to return an integer M, 
in which only one bit is set which at position of lowest set bit of N(from right to left). */

#include <iostream>

using namespace std;

int returnFirstSetBit(int n)
{
    return (n & (-n));
}

int main()
{
    int n;

    cin >> n;

    cout << returnFirstSetBit(n) << endl;

    return 0;
}
