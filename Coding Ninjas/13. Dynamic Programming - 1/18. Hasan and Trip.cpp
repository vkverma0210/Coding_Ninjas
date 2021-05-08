/* Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, 
each city has coordinates on plane, i - th city is in(Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N - th city and 
the sequence of cities he will visit should be increasing in index
(i.e.if he is in city i he can move to city j if and only if i < j).
Visiting i - th city will increase Hasan 's happiness by Fi units 
(including first and last cities), 
also Hasan doesn' t like traveling too much, 
so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness. */

#include <bits/stdc++.h>

using namespace std;

double distance(int x1, int x2, int y1, int y2)
{
    double xDiff = x1 - x2;
    double yDiff = y1 - y2;
    double ans = sqrt(xDiff * xDiff + yDiff * yDiff);

    return ans;
}

double maxHappines(int n, int **arr)
{
    double *dp = new double[n]{};

    dp[0] = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MIN;

        for (int j = i - 1; j >= 0; j--)
        {
            double dis = distance(arr[i][0], arr[j][0], arr[i][1], arr[j][1]);
            dp[i] = max(dp[i], dp[j] - dis);
        }

        dp[i] += arr[i][2];
    }

    double ans = dp[n - 1];
    delete[] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[3];
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    cout << fixed << setprecision(6) << maxHappines(n, arr) << endl;

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}
