/* A plot has been surveyed.
Its boundary consists of segments that form a polygon.
Each segment runs either North - South or East - West.
Calculate the enclosed area.
The i - th character of direction and 
the i - th element of length describe the direction and length of the i - th segment of the polygon 's boundary as the surveyor walked it. 
If you start at the surveyor' s starting point and walk according to the sequence of directions and lengths reported by the surveyor, 
you will traverse the boundary of the polygon, ending up back at the starting point.
This traversal described by the given segments may be either clockwise or counterclockwise. */

#include <bits/stdc++.h>
using namespace std;

double farea(int n, int *arr_x, int *arr_y)
{
    double area = 0;

    for (int i = 1; i < n - 1; i++)
    {
        double x1 = arr_x[i] - arr_x[0];
        double y1 = arr_y[i] - arr_y[0];
        double x2 = arr_x[i + 1] - arr_x[0];
        double y2 = arr_y[i + 1] - arr_y[0];
        double cp = x1 * y2 - x2 * y1;
        area += cp;
    }

    return abs(area / 2);
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int *arr = new int[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int *x_arr = new int[len + 1];
    int *y_arr = new int[len + 1];
    x_arr[0] = 0;
    y_arr[0] = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'N')
        {
            x_arr[i + 1] = x_arr[i];
            y_arr[i + 1] = y_arr[i] + arr[i];
        }
        else if (s[i] == 'S')
        {
            x_arr[i + 1] = x_arr[i];
            y_arr[i + 1] = y_arr[i] - arr[i];
        }
        else if (s[i] == 'W')
        {
            x_arr[i + 1] = x_arr[i] - arr[i];
            y_arr[i + 1] = y_arr[i];
        }
        else if (s[i] == 'E')
        {
            x_arr[i + 1] = x_arr[i] + arr[i];
            y_arr[i + 1] = y_arr[i];
        }
    }

    double ans = farea(len + 1, x_arr, y_arr);
    cout << (int)ans << endl;

    return 0;
}