/* Given two strings S and T, 
write a function to find if T is present as a substring inside S or not. 
If yes, return the starting index otherwise return  -1. */

#include <iostream>

using namespace std;

int *getLps(char pattern[], int len)
{
	int *lps = new int[len]{};

	lps[0] = 0;
	int i = 1;
	int j = 0;

	while (i < len)
	{
		if (pattern[i] == pattern[j])
		{
			lps[i++] = lps[j++] + 1;
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

int findString(char S[], char T[])
{
	int lenText = 0;
	for (int i = 0; S[i] != '\0'; i++)
	{
		lenText++;
	}

	int lenPat = 0;

	for (int i = 0; T[i] != '\0'; i++)
	{
		lenPat++;
	}

	int *lps = getLps(T, lenPat);
	int i = 0, j = 0;

	while (i < lenText && j < lenPat)
	{
		if (S[i] == T[j])
		{
			i++;
			j++;

			if (j == lenPat)
			{
				return i - lenPat;
			}
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}

	return -1;
}

int main()
{
	char S[1000], T[1000];
	cin.getline(S, 1000);
	cin.getline(T, 1000);
	cout << findString(S, T) << endl;

	return 0;
}
