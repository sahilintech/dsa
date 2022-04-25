/*
Search in row and column wise sorted matrix
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
x = 10
O/p : Found at (2,1) (10 is located at index (2,1))
Time: O(r+c)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int r = 4, c = 4;
void search(int arr[r][c], int x)
{
    int i = 0, j = c - 1;
    if(x<arr[0][0] || x>arr[r][c]) // if element is smaller or larger than 1st and last element element of matrix simultaneously then immediately return not found this is a slight optimisation
    {
        cout<<"Not found";
        return;
    }
    while (i < r && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Found at index (" << i << "," << j << ")";
            return;
        }
        else if (x < arr[i][j])
            j--;
        else
            i++;
    }
    cout << "Not found";
}

int main()
{
    int arr[r][c] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    int x = 13; // Element to be searched
    search(arr, x);
    return 0;
}