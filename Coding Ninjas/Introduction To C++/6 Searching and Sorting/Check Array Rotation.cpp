/*You have been given an integer array/list(ARR) of size N. 
It has been sorted(in increasing order) and then rotated by some number 'K' in the clockwise direction.
Your task is to write a function that returns the value of 'K', 
that means, the index from which the array/list has been rotated.*/

#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    for(int i = 0; i < size; i++)
    {
        if(input[i + 1] < input[i])
        {
            if(i == size - 1)
            {
                return 0;
            }
            return i + 1;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}