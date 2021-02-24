/*  Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) 
and Step Size (W), you need to convert all Fahrenheit values from Start to End at the gap of W, 
into their corresponding Celsius values and print the table.  */

#include <iostream>

using namespace std;

void printTable(int start, int end, int step)
{
    while (start <= end)
    {
        int cel = ((start - 32) * 5) / 9;
        cout << start << "\t" << cel << endl;
        start += step;
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;

    printTable(start, end, step);
}
