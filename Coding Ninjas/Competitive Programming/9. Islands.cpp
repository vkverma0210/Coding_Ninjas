/* An island is a small piece of land surrounded by water.
A group of islands is said to be connected if we can reach from any given island to any other island in the same group.
Given V islands(numbered from 1 to V) and E connections or edges between islands.
Can you count the number of connected groups of islands. */

#include <iostream>
#include <queue>

using namespace std;

void bfs_traversal(int **edges, int n, bool *visited, int start)
{
    queue<int> pendingVertices;

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
}

int noOfGroups(int **edges, int n)
{
    bool *visited = new bool[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs_traversal(edges, n, visited, i);
            count++;
        }
    }

    delete[] visited;

    return count;
}

int main()
{
    int n, e;
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

    int count = noOfGroups(edges, n);

    cout << count << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}