/*Reverse the given string word wise. 
That is, the last word in given string should come at 1st place, 
last second word at 2nd place and so on. 
Individual words should remain as it is.*/

#include <iostream>
#include <string.h>

using namespace std;

void reverse(char input[], int s, int e)
{
    while(s < e)
    {
        char temp = input[s];
        input[s] = input[e];
        input[e] = temp;
        s++;
        e--;
    }
}

void reverseStringWordWise(char input[]) 
{
    // Write your code here
    int n = strlen(input);
    
    reverse(input, 0, n - 1);
    
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(input[i] == ' ')
        {
            reverse(input, j, i - 1);
            j = i + 1;
        }
    }
    reverse(input, j, n - 1);
}

int main() 
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
