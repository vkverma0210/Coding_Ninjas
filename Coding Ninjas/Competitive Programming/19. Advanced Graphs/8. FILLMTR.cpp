/* A matrix B (consisting of integers) of dimension N � N is said to be good 
if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|,
where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N � N. 
Q of the entries of this matrix are filled by either 0 or 1. 
You have to identify whether it is possible to fill the remaining entries of matrix B 
(the entries can be filled by any integer, not necessarily by 0 or 1) 
such that the resulting fully filled matrix B is good. */

#include <bits/stdc++.h>

using namespace std;

bool paint(int v, int c, int *color, vector<pair<int, int>> *g)
{
	//Case 1 = if already colored with same color - possible
	if (color[v] == c)
	{
		return true;
	}

	//Case 2 = if already colored with diff colored than required - not possible
	if (color[v] != -1)
	{
		return false;
	}

	// case 3 = not colored
	color[v] = c;

	// now color the adjacent vertices of the current vertex
	for (auto i = g[v].begin(); i != g[v].end(); i++)
	{
		// check if painting possible
		// must be painted with diff color than the current
		if (!paint(i->first, (c + i->second) % 2, color, g))
		{
			return false;
		}
	}

	// if all can be painted
	return true;
}

void solve()
{
	int n, q;
	cin >> n >> q;

	// pair will store - (i),(j,val)
	vector<pair<int, int>> *g = new vector<pair<int, int>>[n + 1];

	// to store colors of all vertices
	int *color = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		color[i] = -1;
	}

	// ATQ if i is connected by j then j is also connected by i with same value
	while (q--)
	{
		int i, j, val;
		cin >> i >> j >> val;
		g[i].push_back(make_pair(j, val));
		g[j].push_back(make_pair(i, val));
	}

	for (int i = 1; i <= n; i++)
	{
		// if vertex in uncolored, color it if possible
		if (color[i] == -1)
		{
			// if coloring is not possible - conflict
			if (!paint(i, 0, color, g))
			{
				cout << "no" << endl;
				return;
			}
		}
	}

	cout << "yes" << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}
