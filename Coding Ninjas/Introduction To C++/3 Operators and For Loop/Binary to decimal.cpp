/* Given a binary number as an integer N, convert it into decimal and print.  */

#include<iostream>

using namespace std;

int main() 
{
	long n;
    cin >> n;
    
    int ans = 0;
    int pv = 1;
    while(n != 0)
    {
        int curr = n % 10;
        ans = ans + pv * curr;
        pv *= 2;
        n /= 10;
    }
    cout << ans << endl;
}
