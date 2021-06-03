/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers),
find and print the path from v1 to v2(if exists).
Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.

Note : 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V - 1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order.
That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix. */

#include <iostream>
#include <vector>

using namespace std;

vector<int> DFS(int **edges, int n, bool *visited, int start, int value)
{
    vector<int> ans;

    if (start == value)
    {
        ans.push_back(start);
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && i != start && edges[start][i] == 1)
        {
            visited[i] = true;

            ans = DFS(edges, n, visited, i, value);

            if (ans.size() != 0)
            {
                ans.push_back(start);
                return ans;
            }
        }
    }

    return ans;
}

vector<int> getPathDFS(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    visited[start] = true;

    vector<int> ans = DFS(edges, n, visited, start, end);

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

    int start, end;
    cin >> start >> end;

    vector<int> ans = getPathDFS(edges, n, start, end);

    if (ans.size() != 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        return 0;
    }

    return 0;
}