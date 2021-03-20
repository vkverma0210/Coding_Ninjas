/* Given a string S, you need to remove all the duplicates. 
That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string. */

#include <bits/stdc++.h>

using namespace std;

string uniqueChar(string str)
{
    string ans;
    unordered_set<char> charSet;

    for (char ch : str)
    {
        if (charSet.find(ch) == charSet.end())
        {
            ans.push_back(ch);
            charSet.insert(ch);
        }
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str) << endl;
}