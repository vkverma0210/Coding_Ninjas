/* Gengar has got an integer N.
Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he 's a special kind of Poke' mon, so he thinks he deserves special permutations.
He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N.

A permutation is called special if it satisfies following condition : 
If Ap &Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself.
"&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations. */

#include <iostream>

using namespace std;

typedef long long ll;

ll permute(int n, int mask, ll *dp)
{
    if (mask == ((1 << (n + 1)) - 2))
    {
        return 1;
    }

    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!(mask & (1 << i)))
        {
            int flag = 1;

            for (int j = 1; j <= n; j++)
            {
                if (mask & (1 << j))
                {
                    if ((i & j) == i)
                    {
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag == 1)
            {
                ans += permute(n, mask | (1 << i), dp);
            }
        }
    }

    dp[mask] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    ll *dp = new ll[1 << (n + 1)]{};

    for (int i = 0; i < (1 << (n + 1)); i++)
    {
        dp[i] = -1;
    }

    ll ans = permute(n, 0, dp);

    cout << ans << "\n";

    return 0;
}
