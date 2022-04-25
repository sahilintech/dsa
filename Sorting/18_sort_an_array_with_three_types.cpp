/*
Sort an array with three types
Given an array containing 0s, 1s and 2s sort this array such 0s come first then 1s and at last 2s.

I/p : {0, 1, 0, 2, 1, 0}
O/p : {0, 0, 0, 1, 1, 2}

Time: 0(n)
Space: O(1)
*/

#include <iostream>
#include <algorithm>
using namespace std;

void threeTypeSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    threeTypeSort(arr, n);
    for (int i : arr)
        cout << i << " ";
    return 0;
}