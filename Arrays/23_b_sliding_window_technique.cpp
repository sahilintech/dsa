// Given an unsorted array of non-negative integers . Find if there is a subarray with given sum
/*
I/p : {1, 4, 20, 3, 10, 5}
sum = 33
O/p : Yes

Note = This approach works only for positive numbers

Approach is based on sliding window technique i.e add each of array to currSum if(currSum<Sum) else subtract element starting from arr[0] from currSum while(currSum> sum)

Time = O(2n) = O(n) because in worst case every element can be traversed two times
eg = {2, 3, 5,, 7, 100}
sum = 100
here every element will be traversed two time.
First time in for loop and when we reach at last element then again every element will be traversed in while loop for removing purpose

*/

#include <iostream>

using namespace std;

bool checkSum(int arr[], int n, int sum)
{
    int currSum = arr[0], start = 0;
    for (int end = 1; end <= n; end++)
    {
        while ((currSum > sum) && (start < end - 1)) // start should not be equal to end here end -1 is written because end starts from 1 starts start from 0 end is already 1 position ahead
        {
            currSum = currSum - arr[start];
            start++;
        }
        if (currSum == sum)
            return true;
        if (end < n)
        {
            currSum += arr[end];
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 8, 30, 5, 20, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 71;
    int val = checkSum(arr, n, sum);
    if(val)
    cout<<"Sum exists";
    else
    cout<<"Sum does not exists";
    return 0;
}
