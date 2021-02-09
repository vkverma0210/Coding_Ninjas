/*Provided with a random integer array/list(ARR) of size N, 
you have been required to sort this array using 'Bubble Sort'.*/

#include <iostream>
using namespace std;

#include <algorithm>

void bubbleSort(int *input, int size)
{
    //Write your code here
    for(int i = 0 ; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(input[j] > input[j + 1])
            {
                swap(input[j], input[j + 1]);
            }
        }
    }
}

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}
}