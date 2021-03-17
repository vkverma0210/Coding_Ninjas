/* In Little Flowers Public School, 
there are many students with same first names. 
You are given a task to find the students with same names. 
You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. 
If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.  */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string names;
    getline(cin, names);

    stringstream ss(names);

    map<string, int> m1;

    string temp;

    while(ss >> temp)
    {
        m1[temp]++;
    }

    map<string, int> :: iterator it = m1.begin();
    int count = 0;

    for(it; it != m1.end(); it++)
    {
        if(it -> second > 1)
        {
            cout << it -> first << " " << it -> second << endl;
            count++;
        }
    }

    if(count == 0)
    {
        cout << -1 << endl;
    }

    return 0;
}