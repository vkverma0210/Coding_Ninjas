/*Given an input string S that contains multiple words, 
you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.*/

#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) 
{
    // Write your code here
    int n = strlen(input);
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(input[i] != ' ')
        {
            input[count++] = input[i];
        }
    }
    
    input[count] = '\0';
}

int main() 
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

