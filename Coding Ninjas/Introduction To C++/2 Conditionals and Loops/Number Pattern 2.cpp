/*Print the following pattern
Pattern for N = 4
    1
   23
  345
 4567  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1, j, k = 0;

    while (i <= n)
    {
        int l = n - i;
        while (l > 0)
        {
            cout << " ";
            l--;
        }
        j = 1;
        while (j <= i)
        {
            cout << j + k;
            j++;
        }
        k++;
        i++;
        cout << endl;
    }

    return 0;
}