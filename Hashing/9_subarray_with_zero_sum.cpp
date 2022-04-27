/*
Given an array. Return true if any subarray of given array has sum zero

I/p : {3, 4, -3, -1, 1}

O/p : true(4-3-1=0)

Time: O(n)
Space: O(n)
*/

#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

bool isSubarray(int arr[], int n)
{
    // insert prefix sum in set and compare if again that prefix sum occurs means in middle some elements has sum as zero
    unordered_set <int> u;
    int prefixSum=0;
    for(int i=0; i<n; i++)
    {
        prefixSum+=arr[i];
        if(u.find(prefixSum)!=u.end())
        return true;
        if(prefixSum==0) // for checking conditon like -2, 3, -1 will give sum as 0 i.e if first some elements give sum as zero then above cannot handle these test cases
        return true;
        u.insert(prefixSum);
    }
    return false;
}

int main(){
    int arr[] = {3, 4, -3, -1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isSubarray(arr, n);
    return 0;
}