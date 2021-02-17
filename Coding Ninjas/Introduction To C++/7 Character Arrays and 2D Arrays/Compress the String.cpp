/*Write a program to do basic string compression. 
For a character which is consecutively repeated more than once, 
replace consecutive duplicate occurrences with the count of repetitions. 
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".*/

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void stringCompression(char input[])
{
    // Write your code here
    int n = strlen(input);

    char temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 49;
        while (i < n - 1 && input[i] == input[i + 1])
        {
            count++;
            i++;
        }

        if (count == 49)
        {
            temp[j++] = input[i];
        }
        else
        {
            temp[j++] = input[i];
            temp[j++] = count;
        }
    }

    temp[j] = '\0';
    strcpy(input, temp);
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str << endl;
}