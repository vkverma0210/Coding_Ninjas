/*For a given input string(str), write a function to print all the possible substrings.
abc

a 
ab 
abc 
b 
bc 
c */

#include <iostream>
#include <cstring>

using namespace std;

void printSubstrings(char input[]) 
{
    // Write your code here
    int n = strlen(input);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n - i; j++)
        {
            int k = i + j - 1;
            for(int l = j; l <= k; l++)
            {
                cout << input[l];
            }
            cout << endl;
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}