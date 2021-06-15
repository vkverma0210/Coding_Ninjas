#include <bits/stdc++.h>

using namespace std;

int *getLps(string pattern)
{
	int len = pattern.length();
	int *lps = new int[len];

	lps[0] = 0;
	int i = 1;
	int j = 0;

	while (i < len)
	{
		if (pattern[i] == pattern[j])
		{
			lps[i] = j + 1;
			j++;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

int main()
{
	string s = "adadabadadabadadad";

	int *arr = getLps(s);

	for (int i = 0; i < s.length(); i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}
