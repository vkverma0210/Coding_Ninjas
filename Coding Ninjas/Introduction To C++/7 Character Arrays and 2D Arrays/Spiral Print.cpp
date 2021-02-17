/*For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. 
That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)*/

#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int mCols)
{
    //Write your code here
    int i, k = 0, l = 0;
    while(k < nRows && l < mCols)
    {
        for(i = l; i < mCols; i++)
        {
            cout << input[k][i] << " ";
        }
        k++;
        
        for(i = k; i < nRows; i++)
        {
            cout << input[i][mCols - 1] << " ";
        }
        mCols--;
        
        if(k < nRows)
        {
            for(i = mCols - 1; i >= l; i--)
            {
                cout << input[nRows - 1][i] << " ";
            }
            nRows--;
        }
        
        if(l < mCols)
        {
            for(i = nRows - 1; i >= k; i--)
            {
                cout << input[i][l] << " ";
            }
            l++;
        }
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
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}