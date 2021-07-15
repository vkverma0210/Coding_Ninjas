/* A convex polygon is a set of n vertices that are joined by n edges, 
such that no two edges intersect and all angles are less than 180 degrees.
We can represent a polygon by listing all the vertices, 
starting at one vertex and following the edges until that vertex is reached again.
Thus, element 0 in the array represents the first vertex.
The first vertex is connected to the second vertex(element 1), 
the second vertex is connected to the third vertex(element 2) and so on.
The last element represents the last vertex, which is connected to the first vertex.
Given the vertices of a polygon, where the x - coordinate of vertex i is element i of int[] x and its y - coordinate is element i of int[] y, 
return its exact area. */

#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    double x, y;
};

class Polygon
{
public:
    Point *points;
    Polygon(int npoints)
    {
        points = new Point[npoints];
    }
};

double area(Polygon p, int n)
{
    double fArea = 0;

    for (int i = 1; i < n - 1; i++)
    {
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
        double x2 = p.points[i + 1].x - p.points[0].x;
        double y2 = p.points[i + 1].y - p.points[0].y;

        double cross_p = x1 * y2 - y1 * x2;
        fArea += cross_p;
    }

    return abs(fArea / 2);
}

int main()
{
    int n;
    cin >> n;
    Polygon p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p.points[i].x;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> p.points[i].y;
    }

    cout << (int)area(p, n) << endl;

    return 0;
}
