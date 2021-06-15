/* The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, 
in an attempt to attract investment.
The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, 
but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations.
Since these are long distance roads connecting major locations in the country
(e.g.cities, large villages, industrial areas), all roads are two - way.
Also, there may be more than one direct road possible between two areas.
This is because there may be several ways to link two areas
(e.g.one road tunnels through a mountain while the other goes around it etc.) 
with possibly differing costs.

A location is considered to have access to an airport either if it contains an airport or 
if it is possible to travel by road to another location from there that has an airport.
You are given the cost of building an airport and a list of possible roads between pairs of locations and 
their corresponding costs.
The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport.
The aim is to make airport access as easy as possible, 
so if there are several ways of getting the minimal cost, 
choose the one that has the most airports. */

#include <bits/stdc++.h>

using namespace std;

class edge
{
public:
    int ei, ej, cost;
};

int find_parent(int num, int *parents, int *rank)
{
    if (num == parents[num])
    {
        return num;
    }

    int p = find_parent(parents[num], parents, rank);

    if (rank[p] <= rank[num])
    {
        parents[p] = num;
        rank[num]++;
    }
    else
    {
        parents[num] = p;
        rank[p]++;
    }

    return p;
}

bool compare(edge e1, edge e2)
{
    return e1.cost < e2.cost;
}

int main()
{
    int t;
    cin >> t;

    for (int it = 1; it <= t; it++)
    {
        int n, m, a;
        cin >> n >> m >> a;

        edge *edges = new edge[m + 1];

        for (int i = 0; i < m; i++)
        {
            cin >> edges[i].ei >> edges[i].ej >> edges[i].cost;
        }

        sort(edges, edges + m, compare);

        int *parents = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }

        int *rank = new int[n + 1]{};

        int cost = 0;
        int j = 0;

        for (int i = 0; i < m && j < n - 1; i++)
        {
            edge e = edges[i];

            if (e.cost >= a)
            {
                break;
            }

            int p1 = find_parent(e.ei, parents, rank);
            int p2 = find_parent(e.ej, parents, rank);

            if (p1 != p2)
            {
                cost += e.cost;

                if (rank[p1] <= rank[p2])
                {
                    parents[p1] = p2;
                    rank[p2]++;
                }
                else
                {
                    parents[p2] = p1;
                    rank[p1]++;
                }

                j++;
            }
        }

        int numAir = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i == parents[i])
            {
                cost += a;
                numAir += 1;
            }
        }

        cout << "Case #" << it << ": " << cost << " " << numAir << endl;
    }

    return 0;
}
