/* Given a graph with N vertices(numbered from 0 to N - 1) and M undirected edges, 
then count the distinct 3 - cycles in the graph.
A 3 - cycle PQR is a cycle in which(P, Q), (Q, R) and (R, P) are connected by an edge. */

#include <iostream>

using namespace std;

int getCount(int **edges, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (edges[j][k] == 1 && edges[k][i] == 1)
                    {
                        count++;
                    }
                }
            }
        }
    }

    return count / 6;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n]{};
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    cout << getCount(edges, n) << endl;
}