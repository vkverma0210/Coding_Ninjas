/* Given an undirected graph G(V, E), check if the graph G is connected graph or not.
Note : 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V - 1. 
2. E is the number of edges present in graph G. */

#include <iostream>
#include <queue>

using namespace std;

bool checkIsConnected(int **edges, int n, int start)
{
    queue<int> pendingVertices;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && i != currentVertices && edges[currentVertices][i] == 1)
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n]{};
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    if (checkIsConnected(edges, n, 0))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}