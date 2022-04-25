// Given a sorted binary array. Count 1s in given array
/*
I/p : {0, 0, 0, 1, 1, 1}
O/p = 3

I/p : {0, 0, 0}
O/p : 0 (There is no 1 present)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int countOnes(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == 0)
            low = mid+1;
        else
        {
            if (mid == 0 || arr[mid-1] != arr[mid]) // other than arr[mid-1]!=arr[mid] we can also write arr[mid-1] == 0 = This also indicates that it is first occurence of 1
                return n-mid;
            else
                high = mid - 1; // If not first occurence of 1 then go to left side
        }
    }
    return 0;
}

int main()
{
    int arr[] = {0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = countOnes(arr, n);
    cout << "No. of ones present are " << val;
    return 0;
}