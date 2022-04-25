// Same as previous but do it in recursive way
// Time = O(log n), Space = O(log n)

#include <iostream>
#include <algorithm>
using namespace std;

int recursiveBinarySearch(int arr[], int n, int low, int high, int ele)
{
    if (low > high) //base case
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == ele)
        return mid;
    else if (arr[mid] > ele)
        return recursiveBinarySearch(arr, n, 0, mid - 1, ele);
    else
        return recursiveBinarySearch(arr, n, mid + 1, high, ele);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 40, 50};
    int *arr1 = new int[0];
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele = 40;
    int val = recursiveBinarySearch(arr, n, 0, n - 1, ele);
    if (val != -1)
        cout << "Element found at index " << val;
    else
        cout << "Not found";
    return 0;
}