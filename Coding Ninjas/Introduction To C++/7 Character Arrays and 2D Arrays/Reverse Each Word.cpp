/*Aadil has been provided with a sentence in the form of a string as a function parameter. 
The task is to implement a function
so as to print the sentence such that each word in the sentence is reversed.*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char input[], int s, int e)
{
    while (s < e)
    {
        char temp = input[s];
        input[s] = input[e];
        input[e] = temp;
        s++;
        e--;
    }
}

void reverseEachWord(char input[])
{
    // Write your code here
    int n = strlen(input);
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
        {
            reverse(input, j, i - 1);
            j = i + 1;
        }
    }
    reverse(input, j, n - 1);
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str << endl;
}