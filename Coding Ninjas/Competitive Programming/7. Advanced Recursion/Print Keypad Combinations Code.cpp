/* Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important.Just print different strings in new lines. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printKeypadSubstring(int num, string output, vector<vector<char>> vec)
{
    if (num == 0 || num == 1)
    {
        cout << output << endl;
        return;
    }

    int rem = num % 10;

    for (int i = 0; i < vec[rem - 2].size(); i++)
    {
        printKeypadSubstring(num / 10, vec[rem - 2][i] + output, vec);
    }
}

void printKeypad(int num)
{
    vector<vector<char>> vec;
    vec.push_back({'a', 'b', 'c'});
    vec.push_back({'d', 'e', 'f'});
    vec.push_back({'g', 'h', 'i'});
    vec.push_back({'j', 'k', 'l'});
    vec.push_back({'m', 'n', 'o'});
    vec.push_back({'p', 'q', 'r', 's'});
    vec.push_back({'t', 'u', 'v'});
    vec.push_back({'w', 'x', 'y', 'z'});

    string output;
    printKeypadSubstring(num, output, vec);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
