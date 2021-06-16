/* A straightforward question. 
Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. 
Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . 
XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. 
Symbol ^ is Exclusive Or. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class trieNode
{
public:
	trieNode *left;
	trieNode *right;
	ll left_ = 0;
	ll right_ = 0;
};

void insert(ll n, trieNode *head)
{
	trieNode *curr = head;

	for (int i = 31; i >= 0; i--)
	{
		int b = (n >> i) & 1;

		if (b == 0)
		{
			curr->left_++;

			if (!curr->left)
			{
				curr->left = new trieNode();
			}

			curr = curr->left;
		}
		else
		{
			curr->right_++;

			if (!curr->right)
			{
				curr->right = new trieNode();
			}

			curr = curr->right;
		}
	}
}

ll findNumSubarray(ll *arr, int n, int k)
{
	ll num_lt = 0;
	ll curr_xor = 0;

	trieNode *head = new trieNode();

	insert(0, head);

	for (int i = 0; i < n; i++)
	{
		curr_xor = curr_xor ^ arr[i];
		trieNode *curr = head;

		if (!curr)
		{
			return 0;
		}

		for (int j = 31; j >= 0; j--)
		{
			int bit_x = (curr_xor >> j) & 1;
			int bit_k = (k >> j) & 1;

			if (bit_x == 1 & bit_k == 1)
			{
				num_lt += curr->right_;

				if (curr->left)
				{
					curr = curr->left;
				}
				else
				{
					break;
				}
			}
			else if (bit_x == 0 & bit_k == 1)
			{
				num_lt += curr->left_;

				if (curr->right)
				{
					curr = curr->right;
				}
				else
				{
					break;
				}
			}
			else if (bit_x == 0 & bit_k == 0)
			{
				if (curr->left)
				{
					curr = curr->left;
				}
				else
				{
					break;
				}
			}
			else if (bit_x == 1 & bit_k == 0)
			{
				if (curr->right)
				{
					curr = curr->right;
				}
				else
				{
					break;
				}
			}
		}

		insert(curr_xor, head);
	}

	return num_lt;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		ll *arr = new ll[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << findNumSubarray(arr, n, k) << endl;
	}

	return 0;
}