// Given array and an index element write position every element smaller than given index element on left side and elements larger than given index element on right side and then position given index element and return its position
/*
Stability is not maintained

I/p : {5,3,8,4,2,7,1,10}
pivot = arr[1] = 5

O/p : 1 3 2 4 8 7 5 10

Time = O(n)
Space = O(1)
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {5,3,8,4,2,7,1,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<hoarePartition(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}