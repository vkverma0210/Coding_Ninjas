/* Given an array of n integers, find subarray whose xor is maximum. */

#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
	trieNode *left;
	trieNode *right;
};

void insert(trieNode *head, int n)
{
	trieNode *curr = head;

	for (int i = 31; i >= 0; i--)
	{
		int b = (n >> i) & 1;

		if (b == 0)
		{
			if (!curr->left)
			{
				curr->left = new trieNode();
			}

			curr = curr->left;
		}
		else
		{
			if (!curr->right)
			{
				curr->right = new trieNode();
			}

			curr = curr->right;
		}
	}
}

int findMaxXorSubarray(int *arr, int n)
{
	trieNode *head = new trieNode();

	insert(head, arr[0]);

	int upto_xor = arr[0];
	int max_xor = arr[0];

	for (int i = 1; i <= n; i++)
	{
		trieNode *curr = head;
		upto_xor = upto_xor ^ arr[i];

		if (upto_xor > max_xor)
		{
			max_xor = upto_xor;
		}

		int curr_max = 0;

		for (int j = 31; j >= 0; j--)
		{
			int b = (upto_xor >> j) & 1;

			if (b == 0)
			{
				if (curr->right)
				{
					curr_max += pow(2, j);
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			else
			{
				if (curr->left)
				{
					curr_max += pow(2, j);
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
			}
		}

		if (curr_max > max_xor)
		{
			max_xor = curr_max;
		}

		insert(head, upto_xor);
	}

	return max_xor;
}

int main()
{
	int n;
	cin >> n;

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << findMaxXorSubarray(arr, n) << endl;

	return 0;
}