/* Gary has a board of size NxM.
Each cell in the board is a coloured dot.
There exist only 26 colours denoted by uppercase Latin characters(i.e.A, B, ..., Z).
Now Gary is getting bored and wants to play a game.
The key of this game is to find a cycle that contain dots of same colour.
Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition : 
1. These k dots are different : if i ≠ j then di is different from dj.
2. k is at least 4. 
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1 : di and di + 1 are adjacent.
Also, dk and d1 should also be adjacent.
Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help.
Your task is to determine if there exists a cycle on the board. */

#include <iostream>
#include <vector>
using namespace std;

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}