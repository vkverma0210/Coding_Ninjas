/* Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well */

#include <iostream>
#include <queue>

using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited)
{
	queue<int> pendingVertices;

	pendingVertices.push(sv);
	visited[sv] = true;

	while (!pendingVertices.empty())
	{
		int currentVertices = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertices << " ";

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
}

void BFS(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			printBFS(edges, n, i, visited);
		}
	}

	delete[] visited;
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

	BFS(edges, n);

	for (int i = 0; i < n; i++)
	{
		delete[] edges[i];
	}

	delete[] edges;

	return 0;
}