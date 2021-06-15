/* This is the story in Zimbo, the kingdom officially made for monkeys. 
Our Code Monk visited Zimbo and declared open a challenge in the kingdom, 
thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. 
The team that returns with the highest number of Bananas will be rewarded 
with as many gold coins as the number of Bananas with them. 
May the force be with you!

Given there are N monkeys in the kingdom. 
Each monkey who wants to team up with another monkey has to perform a ritual. 
Given total M rituals are performed. 
Each ritual teams up two monkeys. 
If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dfs(int n, vector<int> *edges, bool *visited, ll *a, int curr)
{
    visited[curr] = true;
    ll ans = a[curr];
    for (auto i = edges[curr].begin(); i != edges[curr].end(); i++)
    {
        if (!visited[*i])
        {
            ans += dfs(n, edges, visited, a, *i);
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> *edges = new vector<int>[n + 1];

        while (m--)
        {
            int x, y;
            cin >> x >> y;

            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        ll *a = new ll[n + 1]{};

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        bool *visited = new bool[n + 1]{};
        ll maxNums = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ll ans = dfs(n, edges, visited, a, i);

                if (ans > maxNums)
                {
                    maxNums = ans;
                }
            }
        }

        cout << maxNums << endl;
    }

    return 0;
}
