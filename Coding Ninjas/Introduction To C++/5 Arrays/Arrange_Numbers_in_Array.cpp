/*You have been given an empty array(ARR) and its size N. 
The only input taken from the user will be N and you need not worry about the array.
Your task is to populate the array using the integer values in the range 1 to N(both inclusive)
in the order - 1,3,.......4,2.*/

#include <iostream>

using namespace std;

void arrange(int *arr, int n)
{
    //Write your code here
    int mid = (n - 1) / 2;
    int val = 1;
    for (int i = 0; i <= mid; i++)
    {
        arr[i] = val;
        val += 2;
    }

    if (n % 2 == 0)
    {
        val = n;
    }
    else
    {
        val = n - 1;
    }

    for (int i = mid + 1; i < n; i++)
    {
        arr[i] = val;
        val -= 2;
    }
}

//2nd Method
/*
void arrange(int *arr, int n)
{
    //Write your code here
    int s = 0;
    int e = n - 1;
    int val = 1;
    while(s <= e)
    {
        if(val % 2 == 1)
        {
            arr[s++] = val;
        	val++;
        }
        else
        {
            arr[e--] = val;
        	val++;
        }
    }
}
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        arrange(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
}