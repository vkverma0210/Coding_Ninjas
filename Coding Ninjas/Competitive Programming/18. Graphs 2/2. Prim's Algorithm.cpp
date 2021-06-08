/* Given an undirected, connected and weighted graph G(V, E) 
with V number of vertices(which are numbered from 0 to V - 1) and E number of edges.
Find and print the Minimum Spanning Tree(MST) using Prim's algorithm. 

For printing MST follow the steps - 

1. In one line, print an edge which is part of MST in the format - v1 v2 w 
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w.
And v1 <= v2 i.e.print the smaller vertex first while printing an edge.

2. Print V - 1 edges in above format in different lines.
Note : Order of different edges doesn't matter. */

#include <iostream>
#include <climits>

using namespace std;

int getMinVertex(bool *visited, int *weight, int n)
{
    int minVertex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minVertex == -1) || (weight[minVertex] > weight[i])))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

void prims(int **edges, int n)
{
    bool *visited = new bool[n]();
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        //Get minVertex i.e. unvisited vertex with minimum weight

        int minVertex = getMinVertex(visited, weight, n);

        visited[minVertex] = true;

        //Explore all the neighbours of minimum vertex and update parent and weight array according to that

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }

    delete[] parent;
    delete[] visited;
    delete[] weight;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    cout << endl;

    prims(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}