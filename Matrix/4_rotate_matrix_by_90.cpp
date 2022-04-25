/*
Rotate matrix anti-clockwise by 90 degrees
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
O/p : 1 5 9 13
      2 6 10 14
      3 7 11 15
      4 8 12 16
Time: O(n^2)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int n = 4, n = 4;
void rotateMatrix(int arr[n][n])
{
    for (int i = 0; i < n; i++)
        for(int j=i+1; j<n; j++)
            swap(arr[i][j], arr[j][i]);

    for (int i=0; i<n; i++)
    {
        int low=0, high = n-1;
        while(low<high)
        {
            swap(arr[low][i], arr[high][i]);    
            low++;
            high--;
        }
    }
}

int main()
{
    int arr[n][n] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    rotateMatrix(arr);
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
    }
    return 0;
}