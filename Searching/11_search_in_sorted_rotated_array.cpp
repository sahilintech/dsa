#include <iostream>
#include <algorithm>
using namespace std;

int search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > arr[low]) // Left side sorted
        {
            if (x >= arr[low] && x < arr[mid]) // Is element present in left side
                high = mid - 1;
            else
                low = mid + 1;
        }
        else  // Right side sorted
        {
            if (x > arr[mid] && x <= arr[high]) // Is element present in right side
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int val = search(arr, n, x);
    cout << val;
    return 0;
}