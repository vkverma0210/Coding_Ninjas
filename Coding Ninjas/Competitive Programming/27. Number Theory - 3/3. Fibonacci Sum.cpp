/*The fibonacci sequence is defined by the following relation : 
F(0) = 0 F(1) = 1 F(N) = F(N - 1) + F(N - 2), N >= 2 

Your task is very simple.
Given two non - negative integers N and M(N <= M), 
you have to calculate and return the sum(F(N) + F(N + 1) + ... + F(M)) mod 1000000007. */

#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ll;
#define mod 1000000007

void multiply(ll A[2][2], ll M[2][2])
{
    ll fvalue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
    ll svalue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
    ll tvalue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
    ll lvalue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

    A[0][0] = fvalue % mod;
    A[0][1] = svalue % mod;
    A[1][0] = tvalue % mod;
    A[1][1] = lvalue % mod;
}

void power(ll A[2][2], ll n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    power(A, n / 2);

    //Multiplying A ^n/2 with A ^ n/2
    multiply(A, A);

    if ((n % 2) != 0)
    {
        ll M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

ll fib(ll n)
{
    ll A[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
    {
        return 0;
    }

    power(A, n - 1);

    return A[0][0] % mod;
}

unsigned long long fiboSum(unsigned long long m, unsigned long long n)
{
    return (fib(n + 2) % mod - fib(m + 1) % mod + mod) % mod;
}

int main()
{
    unsigned long long m, n;
    cin >> m >> n;
    cout << fiboSum(m, n);
    return 0;
}
