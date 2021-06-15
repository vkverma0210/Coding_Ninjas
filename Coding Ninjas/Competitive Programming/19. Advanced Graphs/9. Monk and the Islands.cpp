/* Monk visits the land of Islands.
There are a total of N islands numbered from 1 to N.
Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts.
He is standing at Island #1 and wants to reach the Island #N.
Find the minimum the number of bridges that he shall have to cross, 
if he takes the optimal route. */

#include <bits/stdc++.h>

using namespace std;

int bfs(int n, vector<int> *edges)
{
    bool *visited = new bool[n]{};

    int *level = new int[n + 1]{};

    queue<int> pending;
    pending.push(0);
    visited[0] = true;

    while (!pending.empty())
    {
        int v = pending.front();
        pending.pop();

        for (int i = 0; i < edges[v].size(); i++)
        {
            int next = edges[v][i];
            if (!visited[next])
            {
                pending.push(next);
                visited[next] = true;
                level[next] = level[v] + 1;
            }
        }
    }

    return level[n - 1];
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
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }

        int numBridges = bfs(n, edges);
        cout << numBridges << endl;
    }

    return 0;
}