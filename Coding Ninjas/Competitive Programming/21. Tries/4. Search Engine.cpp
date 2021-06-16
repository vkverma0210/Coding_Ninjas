/* A straightforward question. 
Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. 
Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . 
XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. 
Symbol ^ is Exclusive Or. */

#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
	trieNode **children;
	int weight;

	trieNode()
	{
		children = new trieNode *[26];

		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}

		weight = 0;
	}
};

void insert(string s, int weight, trieNode *root)
{
	if (s.empty())
	{
		return;
	}

	int index = s[0] - 'a';
	trieNode *child;

	if (root->children[index])
	{
		child = root->children[index];
	}
	else
	{
		child = new trieNode();
		root->children[index] = child;
	}

	if (root->weight < weight)
	{
		root->weight = weight;
	}

	insert(s.substr(1), weight, child);
}

int searchBest(string s, trieNode *root)
{
	int bestWeight = -1;

	trieNode *current = root;

	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		trieNode *child = current->children[index];

		if (child)
		{
			current = child;
			bestWeight = child->weight;
		}
		else
		{
			return -1;
		}
	}

	return bestWeight;
}

int main()
{
	int n, q;
	cin >> n >> q;

	trieNode *root = new trieNode();

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int weight;
		cin >> weight;

		insert(s, weight, root);
	}

	for (int i = 0; i < q; i++)
	{
		string pre;
		cin >> pre;
		cout << searchBest(pre, root) << endl;
	}

	return 0;
}