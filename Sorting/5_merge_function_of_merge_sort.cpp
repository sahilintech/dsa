/*
Given a array in which elements from low to mid are sorted and mid+1 to high are sorted. Sort elements from low to high

I/p: {10, 15, 20, 11, 30}
low = 0
mid = 2
high = 4

O/p: {10, 11, 15, 20, 30}
*/

#include <iostream>
#include <algorithm>
using namespace std;

void mergeFunction(int arr[], int low, int mid, int high)
{
    int l = mid - low + 1;
    int h = high - mid;
    int *left = new int[l];
    int *right = new int[h];
    for (int i = 0; i < l; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < h; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < l && j < h)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < l)
        arr[k++] = left[i++];
    while (j < h)
        arr[k++] = right[j++];
}

int main()
{
    int arr[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
    int low = 0, mid = 3, high = 8;
    mergeFunction(arr, low, mid, high);
    for (int x : arr)
        cout << x << " ";
    return 0;
}