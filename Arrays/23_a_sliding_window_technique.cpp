// ************SLIDING WINDOW TECHNIQUE********************

// Given an array of integers and a number k, find the maximum sum of k consecutive elements
/*
I/p : {1, 8, 30, -5, 20, 7}
    k = 3
3 consecutive elements all sum
1+8+30 = 39
8+30-5 = 33
30-5+20 = 45 ✔️✔️✔️
-5+20+7 = 22

*/

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int maxSumOfKConsec(int arr[], int n, int k)
{
    int currSum = 0;
    for (int i = 0; i < k; i++)
        currSum += arr[i]; // Computing sum of first k elements
    int maxSum = currSum;
    for (int i = k; i < n; i++)
    {
        currSum = currSum + (arr[i] - arr[i - k]); // Exclude first element and include k+ith (k+1) element , exclude 2nd element and include k+ith (k+2) element and so on.
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int val = maxSumOfKConsec(arr, n, k);
    cout << val;
    return 0;
}