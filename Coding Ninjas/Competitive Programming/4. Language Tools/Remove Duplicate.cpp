#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> removeDuplicate(vector<int> input)
{
    vector<int> result;

    sort(input.begin(), input.end());

    result.push_back(input[0]);

    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] != input[i - 1])
        {
            result.push_back(input[i]);
        }
    }

    return result;
}

/*
vector<int> removeDuplicate(vector<int> input)
{
    set<int> s;
    vector<int> result;

    for (int i = 0; i < input.size(); i++)
    {
        if (s.find(input[i]) == s.end())
        {
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }

    return result;
}
*/

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    vector<int> result = removeDuplicate(input);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}