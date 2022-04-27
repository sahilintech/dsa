/*
Given an array. Return the length of longest subarray which is having equal no of 0 and 1

I/p : {1, 0, 1, 1, 1, 0, 0}
O/p : 6 (0, 1, 1, 1, 0, 0)

Time : 0(n)
Space : O(n)
*/

#include<iostream>
#include<algorithm>
#include "0_header.h"
using namespace std;

int longestSubarray(int arr[], int n)
{
    for(int i=0; i<n; i++) // Make all array elements as -1 and now if 0s and 1s will be equal there sum should be 0
    {
        if(arr[i]==0)
        arr[i]=-1;
    }
    longestLength(arr, n, 0); // call the longest length function with given sum as 0
}

int main(){
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longestSubarray(arr, n);
    return 0;
}