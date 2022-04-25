/*
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
O/p : 1 5 9 13
      2 6 10 14
      3 7 11 15
      4 8 12 16
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int r = 4, c = 4;
void transpose(int arr[r][c])
{
    for (int i = 0; i < r; i++)
        for (int j = i+1; j < c; j++)
                swap(arr[i][j], arr[j][i]);
}

int main()
{
    int arr[r][c] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    transpose(arr);
    for (int i = 0; i < r; i++)
    {
        cout << endl;
    for (int j = 0; j < c; j++)
        cout << arr[i][j] << " ";
    }
    return 0;
}