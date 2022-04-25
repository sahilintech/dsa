// Print boundary elements of 2d array.
/*
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
O/p : 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5
Time: 0(r+c)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int r = 4, c = 4;
void boundaryTraversal(int arr[r][c])
{
    if (r == 1) //corner case if there is only one row
        for (int i = 0; i < c; i++)
            cout << arr[0][i];
    else if (c == 1) // corner case if there is only one column
        for (int i = 0; i < r; i++)
            cout << arr[i][0];
    else
    {
        for (int i = 0; i < c; i++)
            cout << arr[0][i] << " ";
        for (int i = 1; i < r; i++)
            cout << arr[i][c - 1] << " ";
        for (int i = c - 2; i >= 0; i--)
            cout << arr[r - 1][i] << " ";
        for (int i = r - 2; i > 0; i--)
            cout << arr[i][0] << " ";
    }
}

int main()
{
    int arr[r][c] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    boundaryTraversal(arr);
    return 0;
}