/* A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run - up to the stairs. */

#include <iostream>
using namespace std;

long getStairCount(int n, long *storage)
{
    if (n == 0 || n == 1)
    {
        storage[n] = 1;
        return storage[n];
    }

    if (n == 2)
    {
        storage[n] = 2;
        return storage[n];
    }

    if (storage[n] != 0)
    {
        return storage[n];
    }

    long ans = getStairCount(n - 1, storage) + getStairCount(n - 2, storage) + getStairCount(n - 3, storage);
    storage[n] = ans;
    return ans;
}

long staircase(int n)
{
    long *storage = new long[n + 1]();

    return getStairCount(n, storage);
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}