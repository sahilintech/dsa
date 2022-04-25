// Find the index of last occurence of element in sorted array by recursion
/*
I/p : {1, 10, 10, 10, 20, 20, 40}
    x = 20
O/p : 5 (Last index of 20)

I/p : {10, 20, 20}
    x = 25
O/p : -1

Time = O(log n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int iterativeLastOcc(int arr[], int n, int ele)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < ele)
            low = mid + 1;
        else if (arr[mid] > ele)
            high = mid - 1;
        else
        {
            if (mid == 0 || arr[mid] != arr[mid+1]) 
                return mid;
            else
                high = mid + 1;  
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 10, 20, 30, 40, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele = 10;
    int val = iterativeLastOcc(arr, n, ele);
    if (val != -1)
        cout << "Element found at index " << val;
    else
        cout << "Not found";
    return 0;
    return 0;
}