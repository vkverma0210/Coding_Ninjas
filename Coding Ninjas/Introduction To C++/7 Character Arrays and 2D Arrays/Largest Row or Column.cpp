/*For a given two-dimensional integer array/list of size (N x M), 
you need to find out which row or column has the largest sum 
(sum of all the elements in a row/column) amongst all the rows and columns.*/

#include <iostream>
#include <climits>
using namespace std;

void findLargest(int **input, int nRows, int mCols)
{
    //Write your code here
    int sum = 0;
    int count = 0;
    int maxSum = INT_MIN;
    int a = 1;
    for (int i = 0; i < nRows; i++)
    {
        sum = 0;
        for (int j = 0; j < mCols; j++)
        {
            sum += input[i][j];
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            count = i;
            a = 1;
        }
    }

    for (int i = 0; i < mCols; i++)
    {
        sum = 0;
        for (int j = 0; j < nRows; j++)
        {
            sum += input[j][i];
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            count = i;
            a = 0;
        }
    }

    if (a == 1)
    {
        cout << "row " << count << " " << maxSum;
    }
    else
    {
        cout << "column " << count << " " << maxSum;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}