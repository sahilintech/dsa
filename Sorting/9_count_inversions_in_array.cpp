/*
A pair (arr[i], arr[j]) forms an inversion when i<j and arr[i]>arr[j]

I/p : {2, 4, 1, 3, 5}
O/p : 3 (Inversions are (2,1), (4,1), (4,3))

I/p : {10, 20, 30, 40}
O/p : 0


Time : O(nlogn)
Space : O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int countAndMerge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[i + low];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = low, res = 0;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
        {
            arr[k++] = rightArr[j++];
            res = res + (n1 - i);
        }
    }
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
    return res;
}

int countInversions(int arr[], int low, int high)
{
    int res = 0;
    if (low < high)
    {
        int mid = (low+high) / 2;
        res += countInversions(arr, low, mid);
        res += countInversions(arr, mid + 1, high);
        res += countAndMerge(arr, low, mid, high);
    }
    return res;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countInversions(arr, 0, n - 1);
    return 0;
}