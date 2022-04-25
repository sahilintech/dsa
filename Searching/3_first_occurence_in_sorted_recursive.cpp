// Find the index of first occurence of element in sorted array by recursion
/*
I/p : {1, 10, 10, 10, 20, 20, 40}
    x = 20
O/p : 4 (First index of 20)

I/p : {10, 20, 20}
    x = 25
O/p : -1

Time = O(log n), Space = O(log n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int recursiveFirstOcc(int arr[], int n, int low, int high, int ele)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (ele > arr[mid])
        return recursiveFirstOcc(arr, n, mid + 1, high, ele);
    else if (ele < arr[mid])
        return recursiveFirstOcc(arr, n, low, mid - 1, ele);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid]) // If element is at first position or previous element is not equal to current mid then it is first occurence
            return mid;
        else
            return recursiveFirstOcc(arr, n, low, mid - 1, ele); // Else go in previous part to find first occurence if above condition fails
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele = 40;
    int val = recursiveFirstOcc(arr, n, 0, n - 1, ele);
    if (val != -1)
        cout << "Element found at index " << val;
    else
        cout << "Not found";
    return 0;
}