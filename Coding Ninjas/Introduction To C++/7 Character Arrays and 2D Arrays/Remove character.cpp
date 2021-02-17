/*For a given a string(str) and a character X, 
write a function to remove all the occurrences of X from the given string.
The input string will remain unchanged if the given character(X) doesn't exist in the input string.*/

#include <iostream>
#include <cstring>

using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) 
{
    // Write your code here
    int n = strlen(input);
    int j = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(input[i] != c)
        {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}


int main() 
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str << endl;
}