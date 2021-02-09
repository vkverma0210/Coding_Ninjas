/*You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. 
Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, 
you will be visiting each element in the array/list just once.*/

#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    //Write your code here
    int i = 0, n0 = 0, n2 = n - 1;
    while(i <= n2)
    {
        if(arr[i] == 0)
        {
            swap(arr[i++], arr[n0++]);
        }
        
        else if(arr[i] == 1)
        {
            i++;
        }
        
        else if(arr[i] == 2)
        {
            swap(arr[i], arr[n2--]);
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
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}