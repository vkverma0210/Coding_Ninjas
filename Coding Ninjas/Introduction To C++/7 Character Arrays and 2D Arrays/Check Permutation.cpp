/*For a given two strings, 'str1' and 'str2', 
check whether they are a permutation of each other or not.*/

#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    // Write your code here
    int m = strlen(input1);
    int n = strlen(input2);
    if (m != n)
    {
        return false;
    }

    int fre[256] = {0};

    for (int i = 0; i < m; i++)
    {
        fre[input1[i]]++;
        fre[input2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (fre[i])
            return false;
    }

    return true;
}

int main()
{
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false") << endl;
}