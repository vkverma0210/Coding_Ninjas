/* Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. 
You just have to populate the output array and return the count of elements populated in the output array. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int keypadSubstring(int num, string output[], vector<vector<char>> vec)
{
    static int index = 0;

    if (num == 0 || num == 1)
    {
        output[index++] = "";
        return index;
    }

    int rem = num % 10;

    index = keypadSubstring(num / 10, output, vec);

    int temp = index;

    for (int i = 0; i < temp; i++)
    {
        string s = output[i];
        output[i] = output[i] + vec[rem - 2][0];

        for (int j = 1; j < vec[rem - 2].size(); j++)
        {
            output[index++] = s + vec[rem - 2][j];
        }
    }

    return index;
}

int keypad(int num, string output[])
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

    return keypadSubstring(num, output, vec);
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
