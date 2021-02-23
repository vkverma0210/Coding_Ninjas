/*Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W), 
you need to convert all Fahrenheit values from Start to End at the gap of W, 
into their corresponding Celsius values and print the table.*/

#include <iostream>

using namespace std;

int main()
{
    int s, e, w;
    cin >> s >> e >> w;

    while (s <= e)
    {
        int c = (5 * (s - 32)) / 9;
        cout << s << "\t" << c << endl;
        s += w;
    }

    return 0;
}
