/* Our college team is going to the sports fest to play a football match with our coach.
There are n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy.
He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team: 
1. Any player can swap with the player directly at front him 
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int player[n];
    for (int i = 0; i < n; i++)
    {
        cin >> player[i];
    }

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs((i + 1) - player[i]) > 2)
        {
            cout << "NO" << endl;
            return 0;
        }

        diff += abs((i + 1) - player[i]);
    }

    cout << "YES" << endl;
    cout << diff / 2 << endl;

    return 0;
}