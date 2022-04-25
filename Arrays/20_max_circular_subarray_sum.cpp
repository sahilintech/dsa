// Given an array. Find the circular subarray having maximum length.
/*
For {10, 5, -5} all circular subarrays are {10}, {5}, {-5}, {10, 5}, {5, -5}, {10, 5, -5},
{5, -5, 10}, {-5, 10}, {-5, 10, 5};

I/p : {5, -2, 3, 4}
O/p : 12 i.e(3+4+5)

I/p : {2, 3, -4}
O/p : 5 i.e(2+3)

*/

#include <iostream>
#include <algorithm>
using namespace std;

int maxNormalSubSum(int arr[], int n)
{
    int res = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(sum + arr[i], arr[i]);
        res = max(res, sum);
    }
    return res;
}

int maxCircSubSum(int arr[], int n)
{
    int maxSumOfNormalSubArray = maxNormalSubSum(arr, n);
    if (maxSumOfNormalSubArray < 0)
        return maxSumOfNormalSubArray;
    int sumOfWholeArray = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfWholeArray += arr[i];
        arr[i] = -arr[i]; 
        // Inverting elements so that same maxNormalSubSum function can find minNormalSubarraySum and we do not have write different function for it
    }
    int minSumofNormalSubArray = maxNormalSubSum(arr, n);
    int res = max(maxSumOfNormalSubArray, (sumOfWholeArray + minSumofNormalSubArray));
    // here above adding wholesum + minsum because elements were inverted.

    return res;
}

int main()
{
    int arr[] = {5, -2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = maxCircSubSum(arr, n);
    cout << val;
    return 0;
}