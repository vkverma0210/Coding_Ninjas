/* You just received another bill which you cannot pay because you lack the money.

Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. 
The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.

You make up your mind to solve the problem where it arises, namely at the parties themselves. 
You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.

You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. 
The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?

Write a program which finds this optimal set of parties that offer the most fun. 
Keep in mind that your budget need not necessarily be reached exactly. 
Achieve the highest possible fun level, and do not spend more money than is absolutely necessary. */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> pairParty(int b, int n, int **p, pair<int, int> **dp)
{
    if (n == 0)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    if (dp[b][n].first != -1 && dp[b][n].second != -1)
    {
        return dp[b][n];
    }

    pair<int, int> result;

    if (p[0][0] <= b)
    {
        pair<int, int> option1 = pairParty(b - p[0][0], n - 1, p + 1, dp);
        option1.first += p[0][0];
        option1.second += p[0][1];

        pair<int, int> option2 = pairParty(b, n - 1, p + 1, dp);

        if (option1.second > option2.second)
        {
            result = option1;
        }
        else if (option1.second < option2.second)
        {
            result = option2;
        }
        else
        {
            if (option1.first > option2.first)
            {
                result = option2;
            }
            else
            {
                result = option1;
            }
        }
    }
    else
    {
        result = pairParty(b, n - 1, p + 1, dp);
    }

    dp[b][n].first = result.first;
    dp[b][n].second = result.second;
    return result;
}

int main()
{
    while (1)
    {
        int budget, n;
        cin >> budget >> n;
        if (budget == 0 && n == 0)
        {
            return 0;
        }

        int **party = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            party[i] = new int[2];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> party[i][0] >> party[i][1];
        }

        pair<int, int> **dp = new pair<int, int> *[budget + 1];

        for (int i = 0; i <= budget; i++)
        {
            dp[i] = new pair<int, int>[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }

        pair<int, int> temp;
        temp = pairParty(budget, n, party, dp);

        cout << temp.first << " " << temp.second << endl;

        for (int i = 0; i <= n; i++)
        {
            delete[] party[i];
        }

        delete party;
    }

    return 0;
}
