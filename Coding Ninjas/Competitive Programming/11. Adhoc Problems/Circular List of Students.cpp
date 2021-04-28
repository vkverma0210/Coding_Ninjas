/* You are given a circular list of students as follows : 
0->1->2->3->4->5->6->7->8->9->10->11 
This list is circular, means that 11 will follow 0 again.
You will be given the student number ‘i’ and some position ‘p’.
You will have to tell that if the list will start from(i + 1) th student, 
then which student will be at pth position. */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int i, p;
        cin >> i >> p;

        int curr = i + 1;
        while (p--)
        {
            if (curr > 11)
            {
                curr = 0;
            }
            curr++;
        }

        curr--;
        if (curr == -1)
        {
            curr = 11;
        }

        cout << curr << endl;
    }

    return 0;
}
