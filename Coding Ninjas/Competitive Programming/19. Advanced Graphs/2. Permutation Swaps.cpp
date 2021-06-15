/* Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. 
Kevin wants to get a permutation Q.
Also he believes that there are M good pairs of integers(ai, bi).
Kevin can perform following operation with his permutation: -

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations. */

#include <bits/stdc++.h>

using namespace std;

void dfs_search(int n, vector<int> *aj, bool *visited, int num, set<int> &s)
{
    visited[num] = true;
    s.insert(num);
    vector<int>::iterator it;

    for (it = aj[num].begin(); it != aj[num].end(); it++)
    {
        if (*it != num && !visited[*it])
        {
            dfs_search(n, aj, visited, *it, s);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int *p = new int[n];
        int *q = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }

        vector<int> *aj = new vector<int>[n + 1];

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            aj[a - 1].push_back(b - 1);
            aj[b - 1].push_back(a - 1);
        }

        bool *visited = new bool[n]{};
        int flag = 1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                set<int> s;

                dfs_search(n, aj, visited, i, s);

                if (s.empty())
                {
                    continue;
                }

                set<int> pset;
                set<int> qset;
                set<int>::iterator inner;

                for (inner = s.begin(); inner != s.end(); inner++)
                {
                    pset.insert(p[*inner]);
                    qset.insert(q[*inner]);
                }

                if (pset != qset)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 0)
            {
                break;
            }
        }

        if (flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
