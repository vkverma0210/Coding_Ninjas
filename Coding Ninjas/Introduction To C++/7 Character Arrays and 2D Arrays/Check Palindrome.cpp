//Given a string, determine if it is a palindrome, considering only alphanumeric characters.

#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) {
    // Write your code here
    int n = strlen(str) - 1;
    int i = 0;
    while(i < n)
    {
        if(str[i] != str[n])
        {
            return false;
        }
        i++;
        n--;
    }
    return true;
}


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false") << endl;
}