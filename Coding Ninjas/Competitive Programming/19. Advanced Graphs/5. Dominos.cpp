/* Dominos are lots of fun. 
Children like to stand the tiles on their side in long lines. 
When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. 
In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, 
the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall. */

#include <bits/stdc++.h>

using namespace std;

void dfs_stack(int n, vector<int> *edges, bool *visited, int i, stack<int> &s)
{
    visited[i] = true;
    vector<int>::iterator it;

    for (it = edges[i].begin(); it != edges[i].end(); it++)
    {
        if (!visited[*it])
        {
            dfs_stack(n, edges, visited, *it, s);
        }
    }

    s.push(i);
}

void dfs(int n, vector<int> *edges, bool *visited, int i)
{
    visited[i] = true;
    vector<int>::iterator it;

    for (it = edges[i].begin(); it != edges[i].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(n, edges, visited, *it);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> *edges = new vector<int>[n];

        while (m--)
        {
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
        }

        stack<int> s;
        bool *visited = new bool[n + 1]{};

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs_stack(n, edges, visited, i, s);
            }
        }

        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
        }

        int count = 0;

        while (!s.empty())
        {
            int i = s.top();
            s.pop();

            if (!visited[i])
            {
                count++;
                dfs(n, edges, visited, i);
            }
        }

        cout << count << endl;
    }

    return 0;
}