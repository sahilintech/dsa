// Given s sorted array. Find index of given element to be searched else return -1
// Time = O(log n)

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int ele)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }
        else if (arr[mid] > ele) // Element is on right hand side of mid so high will be equal to mid -1
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 10, 20, 30, 40, 40, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 10; // Element to be searched
    int val = binarySearch(arr, n, element);
    if (val != -1)
        cout << "Element found at index " << val;
    else
        cout << "Not found";
    return 0;
}