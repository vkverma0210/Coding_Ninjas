/* You are given a sequence A[1], A[2], ..., A[N], ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 = i = N, and x, 0 = x = 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 = x < y = N.
You must find i and j such that x = i, j = y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j]. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node
{
	int mx = 0;
	int smx = 0;
};

void build_tree(int *a, node *tree, int s, int e, int i)
{
	if (s == e)
	{
		tree[i].mx = a[s];
		tree[i].smx = INT_MIN;
		return;
	}

	int mid = (s + e) / 2;

	build_tree(a, tree, s, mid, 2 * i);

	build_tree(a, tree, mid + 1, e, 2 * i + 1);

	tree[i].mx = max(tree[2 * i].mx, tree[2 * i + 1].mx);

	tree[i].smx = min(max(tree[2 * i].smx, tree[2 * i + 1].mx), max(tree[2 * i + 1].smx, tree[2 * i].mx));
}

node query_tree(node *tree, int s, int e, int i, int l, int r)
{
	// Completely outside given range
	if (e < l || s > r)
	{
		node a;
		a.mx = INT_MIN;
		a.smx = INT_MIN;
		return a;
	}

	// Completely inside given range
	if (s >= l && e <= r)
	{
		return tree[i];
	}

	// Partially inside ans partially outside
	int mid = (s + e) / 2;

	node lans = query_tree(tree, s, mid, 2 * i, l, r);

	node rans = query_tree(tree, mid + 1, e, 2 * i + 1, l, r);

	node ans;
	ans.mx = max(lans.mx, rans.mx);
	ans.smx = min(max(lans.mx, rans.smx), max(lans.smx, rans.mx));
	return ans;
}

void update_tree(int *a, node *tree, int s, int e, int i, int index, int val)
{
	if (s == e)
	{
		a[index] = val;
		tree[i].mx = val;
		tree[i].smx = INT_MIN;
		return;
	}

	int mid = (s + e) / 2;
	if (index > mid)
	{
		update_tree(a, tree, mid + 1, e, 2 * i + 1, index, val);
	}
	else
	{
		update_tree(a, tree, s, mid, 2 * i, index, val);
	}

	tree[i].mx = max(tree[2 * i].mx, tree[2 * i + 1].mx);
	tree[i].smx = min(max(tree[2 * i].mx, tree[2 * i + 1].smx), max(tree[2 * i].smx, tree[2 * i + 1].mx));
}

void view_tree(int n, node *tree)
{
	for (int i = 1; i <= 4 * n; i++)
	{
		cout << tree[i].mx << " " << tree[i].smx << "\n";
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	node *tree = new node[4 * n];

	build_tree(a, tree, 1, n, 1);
	// view_tree(n, tree);

	int q;
	cin >> q;
	while (q--)
	{
		char qType;
		int x, y;
		cin >> qType >> x >> y;
		if (qType == 'Q')
		{
			node ans = query_tree(tree, 1, n, 1, x, y);
			cout << ans.mx + ans.smx << endl;
		}
		else
		{
			update_tree(a, tree, 1, n, 1, x, y);
			// view_tree(n, tree);
		}
	}

	delete a;
	return 0;
}