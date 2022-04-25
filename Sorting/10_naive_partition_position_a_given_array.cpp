// Given array and an index element write position every element smaller than given index element on left side and elements larger than given index element on right side and then position given index element and return its position
/*
Maintain stability
I/p : {3, 8, 6, 12, 10, 7}
    i = 5

O/p : {3, 6, 7, 12, 10} or {6, 3, 5, 12, 10} or .....

Time : 0(n)
Space : 0(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int naivePartition(int arr[], int low, int high, int pivot)
{
    int *temp = new int[high - low + 1];
    int index = 0;
    for (int i = low; i <= high; i++)
        if (arr[i] < arr[pivot])
            temp[index++] = arr[i];
    for (int i = low; i <= high; i++)
        if (arr[i] == arr[pivot])
            temp[index++] = arr[i];
    int res = low + index - 1; // -1 because index is incremented by 1 in above for loop
    for (int i = low; i <= high; i++)
        if (arr[i] > arr[low])
            temp[index++] = arr[i];
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low]; // i-low because temp array elements should be started copying from 0th element in main array
    return res;
}

int main()
{
    int arr[] = {3, 8, 6, 12, 10, 7};
    int p = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<naivePartition(arr, 0, n - 1, p);
    return 0;
}