/* You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time. */

#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main()
{
    //Write your code here

    int n;
    cin >> n;

    vector<pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        time.push_back(make_pair(start, end));
    }

    sort(time.begin(), time.end(), compare);

    pair<int, int> prev;
    prev.first = time[0].first;
    prev.second = time[0].second;

    int count = 1;

    for (int i = 1; i < time.size(); i++)
    {
        if (time[i].first >= prev.second)
        {
            count++;
            prev.first = time[i].first;
            prev.second = time[i].second;
        }
    }

    cout << count << endl;

    return 0;
}