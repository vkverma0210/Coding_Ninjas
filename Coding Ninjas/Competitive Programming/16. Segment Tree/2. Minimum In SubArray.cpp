/* Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y. */

#include <bits/stdc++.h>

using namespace std;

void buildTree(int *a, int *tree, int s, int e, int i)
{
	if (s == e)
	{
		tree[i] = a[s];
		return;
	}

	int mid = (s + e) / 2;

	buildTree(a, tree, s, mid, 2 * i);

	buildTree(a, tree, mid + 1, e, 2 * i + 1);

	tree[i] = min(tree[i * 2], tree[2 * i + 1]);
	return;
}

void updateTree(int *arr, int *tree, int s, int e, int i, int index, int val)
{
	if (s == e)
	{
		arr[index] = val;
		tree[i] = val;
		return;
	}

	int mid = (s + e) / 2;

	if (index > mid)
	{
		updateTree(arr, tree, mid + 1, e, 2 * i + 1, index, val);
	}
	else
	{
		updateTree(arr, tree, s, mid, 2 * i, index, val);
	}

	tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

int queryTree(int *tree, int s, int e, int i, int l, int r)
{
	// Completely outside given range
	if (l > e || r < s)
	{
		return INT_MAX;
	}

	// Completely inside given range
	if (s >= l && e <= r)
	{
		return tree[i];
	}

	// Partially inside ans partially outside
	int mid = (s + e) / 2;
	int lmin = queryTree(tree, s, mid, 2 * i, l, r);
	int rmin = queryTree(tree, mid + 1, e, 2 * i + 1, l, r);

	return min(lmin, rmin);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	int *arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int *tree = new int[4 * n + 1]{};

	buildTree(arr, tree, 1, n, 1);

	while (q--)
	{
		char qtype;
		int first, second;
		cin >> qtype >> first >> second;

		if (qtype == 'u')
		{
			updateTree(arr, tree, 1, n, 1, first, second);
		}
		else
		{
			int ans = queryTree(tree, 1, n, 1, first, second);
			cout << ans << endl;
		}
	}

	delete[] arr;
	delete[] tree;

	return 0;
}