// Quick sort . place the pivot element in correct position using lomuto partition and sort both sides of pivot element

#include <iostream>
#include <algorithm>
#include "0_header.h"
using namespace std;

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = lomutoPartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}