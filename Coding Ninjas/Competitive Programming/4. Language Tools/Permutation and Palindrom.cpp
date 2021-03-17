#include <bits/stdc++.h>

using namespace std;

char getChar(int i)
{
    return (char)(i + 97);
}

void printPalindromicString(string str)
{
    map<char, vector<int>> index;

    for (int i = 0; i < str.length(); i++)
    {
        index[str[i]].push_back(i);
    }

    int odd_freq_count = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((index[getChar(i)].size() % 2) != 0)
        {
            odd_freq_count++;
        }
    }

    if (odd_freq_count >= 2)
    {
        cout << "-1";
        return;
    }

    int ans[str.length()];
    int start = 0;
    int end = str.length() - 1;

    for (int i = 0; i < 26; i++)
    {
        char currentChar = getChar(i);
        for (int j = 0; j < index[currentChar].size(); j += 2)
        {
            if ((index[currentChar].size() - j) == 1)
            {
                ans[str.length() / 2] = index[currentChar][j];
                continue;
            }

            ans[start] = index[currentChar][j];
            ans[end] = index[currentChar][j + 1];
            start++;
            end--;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << ans[i] + 1 << " ";
    }

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        printPalindromicString(str);

        cout << endl;
    }

    return 0;
}