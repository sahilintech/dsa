/*
Given a matrix which is sorted row wise. Find its median
I/p : 5 10 20 30 40
      1 2 3 4 6
      11 13 15 17 19
O/p : 13
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int r = 3, c = 5;
int returnMedian(int arr[r][c])
{
    int min = arr[0][0], max = arr[0][c - 1]; // since rows are sorted min element will be found anywhere in first column and max element can be found anywhere in the last column
    for (int i = 1; i < r; i++)
    {
        if (arr[i][0] < min)
            min = arr[i][0];
        if (arr[i][c - 1] > max)
            max = arr[i][c - 1];
    }
    int medPos = (r * c + 1) / 2; // Find the position of  median i.e total elements + 1 whole divide by 2
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;
        for (int i = 0; i < r; i++)
            midPos += upper_bound(arr[i], arr[i] + c, mid) - arr[i];
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min; // we can return max also
}

int main()
{
    int arr[r][c] = {{5, 10, 20, 30, 40},
                     {1, 2, 3, 4, 6 },
                     {11, 13, 15, 17, 19}};

    cout << returnMedian(arr);
    return 0;
}