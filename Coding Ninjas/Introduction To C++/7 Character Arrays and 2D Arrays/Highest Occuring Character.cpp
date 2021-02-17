/*For a given a string(str), find and return the highest occurring character.*/

#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) 
{
    // Write your code here
    int n = strlen(input);
    int fre[256] = {0};
    
    for(int i = 0; i < n; i++)
    {
        fre[input[i]]++;
    }
    
    int max = 0;
    char c = input[0];
    max = fre[input[0]];
    
    for(int i = 1; i < n; i++)
    {
        if(fre[input[i]] > max)
        {
            max = fre[input[i]];
            c = input[i];
        }
    }
    
    return c;
}

int main() 
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str) << endl;
}