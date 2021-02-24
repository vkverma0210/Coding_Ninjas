/* Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Note : If a number has trailing zeros, then its reverse will not include them. 
For e.g., reverse of 10400 will be 401 instead of 00401.  */

#include<iostream>

using namespace std;

int main() 
{
	int n;
    cin >> n;
    
    int rev = 0;
    while(n != 0)
    {
        int curr = n % 10;
        rev = rev * 10 + curr;
        n /= 10;
    }
    cout << rev << endl;

    return 0;
}
