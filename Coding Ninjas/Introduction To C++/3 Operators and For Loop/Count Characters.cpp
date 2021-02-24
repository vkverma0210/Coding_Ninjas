/* Write a program to count and print the total number of characters (lowercase english alphabets only), 
digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).  */

#include <iostream>

using namespace std;

int main()
{
    char c;
    int al = 0, num = 0, s = 0;

    c = cin.get();
    while (c != '$')
    {
        if (c >= 'a' && c <= 'z')
            al++;
        else if (c >= '0' && c <= '9')
            num++;
        else if (c == ' ' || c == '\n' || c == '\t')
            s++;

        c = cin.get();
    }

    cout << al << " " << num << " " << s << endl;

    return 0;
}