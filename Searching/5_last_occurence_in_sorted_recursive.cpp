// Find the index of last occurence of element in sorted array by recursion
/*
I/p : {1, 10, 10, 10, 20, 20, 40}
    x = 20
O/p : 5 (Last index of 20)

I/p : {10, 20, 20}
    x = 25
O/p : -1

Time = O(log n), Space = O(log n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int recursiveLastOcc(int arr[], int n, int low, int high, int ele)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] < ele)
        return recursiveLastOcc(arr, n, mid + 1, high, ele);
    else if (arr[mid] > ele)
        return recursiveLastOcc(arr, n, low, mid - 1, ele);
    else
    {
        if ((mid == n - 1) || (arr[mid] != arr[mid+1]))
            return mid;
        else
            return recursiveLastOcc(arr, n, mid + 1, high, ele);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 40, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele = 50;
    int val = recursiveLastOcc(arr, n, 0, n - 1, ele);
    if (val != -1)
        cout << "Element found at index " << val;
    else
        cout << "Not found";
    return 0;
}