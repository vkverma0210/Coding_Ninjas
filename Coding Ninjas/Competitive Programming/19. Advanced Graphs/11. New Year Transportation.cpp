/* New Year is coming in Line World! 
In this world, there are n cells numbered by integers from 1 to n, as a 1 × n board.
People live in cells.
However, it was hard to move between distinct cells, 
because of the difficulty of escaping the cell.
People wanted to meet people who live in other cells.

So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year.
First, he thought of n - 1 positive integers a1, a2, ..., an - 1. 
For every integer i where 1 ≤ i ≤ n - 1 the condition 1 ≤ ai ≤ n - i holds.
Next, he made n - 1 portals, numbered by integers from 1 to n - 1. 
The i - th(1 ≤ i ≤ n - 1) portal connects cell i and cell(i + ai), and one can travel from cell i to cell(i + ai) using the i - th portal.

Unfortunately, one cannot use the portal backwards, which means one cannot move from cell(i + ai) to cell i using the i - th portal.
It is easy to see that because of condition 1 ≤ ai ≤ n - i one can't leave the Line World using portals.

Currently, I am standing at cell 1, and I want to go to cell t.
However, I don't know whether it is possible to go there. 
Please determine whether I can go to cell t by only using the construted transportation system. */

#include <bits/stdc++.h>

using namespace std;

int dfs(int n, int t, vector<int> *edges, int *a, int curr, bool *visited)
{
    if (curr == t)
    {
        return 1;
    }

    visited[curr] = true;

    for (auto i = edges[curr].begin(); i != edges[curr].end(); i++)
    {
        if (!visited[*i])
        {
            return dfs(n, t, edges, a, *i, visited);
        }
    }

    return 0;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> *edges = new vector<int>[n + 1];

    int *a = new int[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        edges[i].push_back(i + a[i]);
    }

    bool *visited = new bool[n + 1]{};

    int ans = dfs(n, t, edges, a, 1, visited);

    if (ans == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}