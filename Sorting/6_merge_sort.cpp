/*
Divide array in half sort two parts and merge them
Time: 0(nlogn)
Space: O(n)
*/

#include <iostream>
#include <algorithm>
#include "0_header.h"
using namespace std;

void mergeSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeFunction(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {10, 3, 2, 16, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i : arr)
        cout << i <<" ";
    return 0;
}