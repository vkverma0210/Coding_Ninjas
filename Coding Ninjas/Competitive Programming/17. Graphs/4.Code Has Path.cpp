/* Given an undirected graph G(V, E)
and two vertices v1 and v2(as integers), 
check if there exists any path between them or not.
Print true if the path exists and false otherwise.
Note : 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V - 1. 
2. E is the number of edges present in graph G. */

#include <iostream>
#include <queue>

using namespace std;

bool printDFS(int **edges, int n, bool *visited, int start, int value)
{
    if (start == value)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (edges[start][i] == 1 && !visited[i] && i != start)
        {
            visited[start] = true;

            bool ans = printDFS(edges, n, visited, i, value);

            if (ans == true)
            {
                return ans;
            }
        }
    }
    return false;
}

bool printBFS(int **edges, int n, bool *visited, int start, int value)
{
    if (start == value)
    {
        return true;
    }

    if (edges[start][value] == 1)
    {
        return true;
    }

    queue<int> pendingVertices;

    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == currentVertices)
            {
                continue;
            }

            if (edges[currentVertices][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    if (visited[value])
    {
        return true;
    }

    return false;
}

bool DFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool ans = printDFS(edges, n, visited, v1, v2);
    delete[] visited;

    return ans;
}

bool BFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool ans = printBFS(edges, n, visited, v1, v2);
    delete[] visited;

    return ans;
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

    int v1, v2;
    cin >> v1 >> v2;

    // bool ans = DFS(edges, n, v1, v2);
    bool ans = BFS(edges, n, v1, v2);

    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}