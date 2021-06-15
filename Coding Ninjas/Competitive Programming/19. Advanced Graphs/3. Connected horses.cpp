/* You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. 
Well, here we have for you a similar N*M size board with similar arrangement of 
black and white cells.
A few of these cells have Horses placed over them. 
Each horse is unique. 
Now these horses are not the usual horses which could jump to any of the 
8 positions they usually jump in. 
They can move only if there is another horse on one of the 8-positions that 
it can go to usually and then both the horses will swap their positions. 
This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways 
that the horses occupy the board! 
Given the state of the board, calculate answer. 
Since this answer may be quite large, calculate in modulo 10^9 + 7. */

#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001];
#define mod 1000000007;
typedef long long ll;

ll fact(ll t)
{
    int ans = 1;
    for (ll i = 1; i <= t; i++)
    {
        ans = (ans * i) % mod;
    }

    return ans;
}

void dfs_search(int n, int m, bool **visited, int i, int j, set<pair<int, int>> &s)
{
    if (visited[i][j] == true)
    {
        return;
    }

    s.insert(make_pair(i, j));
    visited[i][j] = true;
    int x = i;
    int y = j;

    // top
    if (x - 2 >= 0 && y - 1 >= 0)
    {
        if (grid[x - 2][y - 1] == 1)
        {
            dfs_search(n, m, visited, x - 2, y - 1, s);
        }
    }

    if (x - 2 >= 0 && y + 1 <= m)
    {
        if (grid[x - 2][y + 1] == 1)
        {
            dfs_search(n, m, visited, x - 2, y + 1, s);
        }
    }

    // left
    if (x - 1 >= 0 && y - 2 >= 0)
    {
        if (grid[x - 1][y - 2] == 1)
        {
            dfs_search(n, m, visited, x - 1, y - 2, s);
        }
    }

    if (x + 1 <= n && y - 2 >= 0)
    {
        if (grid[x + 1][y - 2] == 1)
        {
            dfs_search(n, m, visited, x + 1, y - 2, s);
        }
    }

    // bottom
    if (x + 2 <= n && y - 1 >= 0)
    {
        if (grid[x + 2][y - 1] == 1)
        {
            // cout<<"BL\n";
            dfs_search(n, m, visited, x + 2, y - 1, s);
        }
    }

    if (x + 2 <= n && y + 1 <= m)
    {
        if (grid[x + 2][y + 1] == 1)
        {
            dfs_search(n, m, visited, x + 2, y + 1, s);
        }
    }

    // right
    if (x - 1 >= 0 && y + 2 <= m)
    {
        if (grid[x - 1][y + 2] == 1)
        {
            dfs_search(n, m, visited, x - 1, y + 2, s);
        }
    }

    if (x + 1 <= n && y + 2 <= m)
    {
        if (grid[x + 1][y + 2] == 1)
        {
            dfs_search(n, m, visited, x + 1, y + 2, s);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                grid[i][j] = 0;
            }
        }

        // coordinates of horses
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
        }

        set<set<pair<int, int>>> output;

        bool **visited = new bool *[n + 1];

        for (int i = 1; i <= n; i++)
        {
            visited[i] = new bool[m + 1]{};
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    set<pair<int, int>> s;
                    dfs_search(n, m, visited, i, j, s);
                    output.insert(s);
                }
            }
        }

        long long int ansfinal = 1;
        set<set<pair<int, int>>>::iterator itout;
        for (itout = output.begin(); itout != output.end(); itout++)
        {
            int setsize = itout->size();
            if (setsize == 0)
            {
                continue;
            }

            ansfinal = (ansfinal * fact(setsize)) % mod;
        }

        cout << ansfinal << endl;
    }

    return 0;
}