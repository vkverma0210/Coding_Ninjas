/* Given an undirected graph G(V, E), find and print all the connected components of the given graph G.

Note : 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V - 1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components.
And then print them in the main, not inside function.
Print different components in new line.And each component should be printed in increasing order(separated by space).
Order of different components doesn't matter. */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> getConnectedComponents(int **edges, int n, bool *visited, int start)
{
    queue<int> pendingVertices;
    vector<int> ans;

    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();
        ans.push_back(currentVertices);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && i != currentVertices && edges[currentVertices][i] == 1)
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}

vector<vector<int>> getAns(int **edges, int n)
{
    bool *visited = new bool[n];
    vector<vector<int>> components;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans = getConnectedComponents(edges, n, visited, i);
            components.push_back(ans);
        }
    }

    delete[] visited;

    return components;
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

    vector<vector<int>> allComponents = getAns(edges, n);

    for (int i = 0; i < allComponents.size(); i++)
    {
        sort(allComponents[i].begin(), allComponents[i].end());
        for (int j = 0; j < allComponents[i].size(); j++)
        {
            cout << allComponents[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}