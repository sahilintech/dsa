// Given array and an index element write position every element smaller than given index element on left side and elements larger than given index element on right side and then position given index element and return its position
/*
Stability is not maintained

I/p : {10, 80, 30, 90, 40, 50, 70}
pivot = arr[6] = 70

O/p : index of pivot element is 4 {10, 30, 40, 50, 70, 80, 90}

Time = O(n)
Space = O(1)
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int lomutoPartition(int arr[], int low, int high)
{
  //swap(arr[pivot], arr[high]) if pivot is not last element and user enter any index for pivot element then swap last and pivot element then proceed.
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    return (i + 1);
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lomutoPartition(arr, 0, n - 1);
    return 0;
}