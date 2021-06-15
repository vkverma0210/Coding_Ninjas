/* Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. 
You just need to calculate the count, not the substrings. */

#include <iostream>

using namespace std;

int countPalindromeSubstrings(char s[])
{

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	int l, r, count = 0;

	for (int i = 0; i < len; i++)
	{
		//Odd Length
		l = i;
		r = i;

		while (l >= 0 && r < len && s[l] == s[r])
		{
			count++;
			l--;
			r++;
		}

		//Even Length
		l = i;
		r = i + 1;

		while (l >= 0 && r < len && s[l] == s[r])
		{
			int curr_l = r - l + 1;

			count++;
			l--;
			r++;
		}
	}

	return count;
}

int main()
{
	char input[10000];
	cin >> input;

	cout << countPalindromeSubstrings(input) << endl;
}
