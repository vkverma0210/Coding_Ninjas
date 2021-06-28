/* Given an array of n positive integers.
The task is to count the number of Arithmetic Progression subsequences in the array.
As the answer could be very large, output it modulo 100001. 

Note : Empty sequence or single element sequence is Arithmetic Progression. */

#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

#define mod 100001
typedef long long ll;

int numofAP(int *arr, int N)
{
    ll ans = N + 1;

    unordered_map<int, int> *m = new unordered_map<int, int>[N];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int diff = arr[j] - arr[i];

            m[i][diff] += 1;

            ans = (ans + 1) % mod;
        }
    }

    for (int i = N - 3; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int diff = arr[j] - arr[i];

            m[i][diff] = (m[i][diff] % mod + m[j][diff] % mod) % mod;
            ans = (ans % mod + m[j][diff] % mod) % mod;
        }
    }

    delete[] m;

    return ans;
}

int main()
{

    int N;
    cin >> N;

    int *arr = new int[N + 1];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << numofAP(arr, N) << endl;

    return 0;
}
