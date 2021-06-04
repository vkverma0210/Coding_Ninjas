/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2(if exists).
Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note : 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V - 1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order.That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix. */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

void getPathBFS(int **edges, int n, int start, int value)
{
    queue<int> pendingVertices;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pendingVertices.push(start);
    visited[start] = true;

    map<int, int> m;

    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && currentVertices != i && edges[currentVertices][i] == 1)
            {
                pendingVertices.push(i);
                visited[i] = true;
                m[i] = currentVertices;
            }
        }
    }

    if (!visited[value])
    {
        return;
    }

    int index = value;
    cout << value << " ";
    while (index != start)
    {
        cout << m[index] << " ";
        index = m[index];
    }

    return;
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

    int start, end;
    cin >> start >> end;

    getPathBFS(edges, n, start, end);

    return 0;
}