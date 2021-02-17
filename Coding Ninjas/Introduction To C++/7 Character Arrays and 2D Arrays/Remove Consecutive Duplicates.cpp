/*For a given string(str), remove all the consecutive duplicate characters.*/

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    // Write your code here
    int n = strlen(input);
    int j = 1;
    char nextc = input[0];

    for (int i = 1; i < n; i++)
    {
        if (input[i] != nextc)
        {
            input[j++] = input[i];
            nextc = input[i];
        }
    }
    input[j] = '\0';
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str << endl;
}