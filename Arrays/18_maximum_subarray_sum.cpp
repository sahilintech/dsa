// Given an array . Print the maximum of its subarray.
/*
I/p = {2, 3, -8, 7, -1, 2, 3}
O/p = 11
because 7 + (-1) + 2 + 3 = 11

I/p = {5, 8, 3}
O/p = 16

Time: O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int maxSubarrSum(int arr[], int n)
{
    int sum = arr[0], res = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(arr[i] + sum, arr[i]); // We check if present element is greater or (max of previous subarray + currElement is greater)
        res = max(res, sum);             // Check if previous if previous res is greater or current sum is greater
    }
    return res;
}

int main()
{
    int arr[] = {-6, -1, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = maxSubarrSum(arr, n);
    cout << val;
    return 0;
}