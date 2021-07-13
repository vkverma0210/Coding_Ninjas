/* We all know Sanchit Lee Cooper who is a Caltech theoretical physicist. 
He has eccentric and arrogant behavior. 
Due to his belief that he's intellectually superior, he's not ashamed to insult his own friends, like Howard, 
who is an engineer and not a real scientist. 
But nobody messes with an engineer. 
So Howard accepted an challenge from Sanchit. 
Sanchit was involved in numerous experiments as a wunderkind, such as his plan for building his own nuclear reactor - a plan stopped by government. 
So Sanchit presented Howard with a problem about his own nuclear reactor. 
It contains a large tank and at each second an atom is introduced in the tank which reacts with already existing atoms and produces some energy. 
Also he defined a special threshold number for his reactor called Cooper number m which is always a prime number. 
Energy output is defined as previous energy output of the tank multiplied by number of atoms present in it. 
But due to some special condition of the tank, all atoms attains stable state when number of atoms are multiple of Cooper number and no new reaction occurs. 
Energy output in this case is same as previous case. 
Also initial energy of the reactor is 1 and initially there is no atom in the tank. 
Now Sanchit ask Howard to tell the energy output after time T. 
But sadly Howard is not able to solve it and ask for your help. */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fact(int a, int m)
{
    ll res = 1;

    for (int i = 2; i <= a; i++)
    {
        res = ((res % m) * (i % m)) % m;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        ll t, m;
        cin >> t >> m;

        if (t < m)
        {
            if (m - t == 1)
            {
                cout << 1 << "\n";
                continue;
            }
            else
            {
                cout << fact(t, m) % m << "\n";
                continue;
            }
        }
        else
        {
            ll last = t % m;
            ll ans = fact(last, m) % m;

            if ((t / m) % 2 == 0)
            {
                cout << ans << "\n";
            }
            else
            {
                cout << ((m - 1) % m * ans % m) % m << "\n";
            }
        }
    }

    return 0;
}