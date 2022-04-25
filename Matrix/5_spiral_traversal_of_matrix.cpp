/*
Rotate matrix anti-clockwise by 90 degrees
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
O/p : 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
Time: O(r*c)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int r = 4, c = 4;
void spiralTraversal(int arr[r][c])
{
    int topRow = 0, rightCol = c - 1, bottomRow = r - 1, leftCol = 0;
    while (topRow <= bottomRow && leftCol <= rightCol)
    {
        for (int i = leftCol; i <= rightCol; i++) // Printing top most row of matrix i.e(the topmost row is simply the count of columns so for loop is made from colcount as 0 to last col.)
            cout << arr[topRow][i] << " ";
        topRow++; // now firstrow is printed so make 2nd row as toprow

        for (int i = topRow; i <= bottomRow; i++)
            cout << arr[i][rightCol] << " ";
        rightCol--;
        if (topRow <= bottomRow)
        {
            for (int i = rightCol; i >= leftCol; i--)
                cout << arr[bottomRow][i] << " ";
            bottomRow--;
        }
        if (leftCol <= rightCol)
        {
            for (int i = bottomRow; i >= topRow; i--)
                cout << arr[i][leftCol] << " ";
            leftCol++;
        }
    }
}

int main()
{
    int arr[r][c] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    spiralTraversal(arr);
    return 0;
}