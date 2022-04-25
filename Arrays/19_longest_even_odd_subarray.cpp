// Given an array . Find the length of longest subarray containing elements as odd, even, odd, even.... or even, odd, even, odd.....
/*
I/p : {10, 12, 14, 7, 8}
O/p : 3   working = (14, 7, 8) i.e even odd even

I/p : {7, 10, 13, 14}
O/p : 4  odd, even, odd, even

I/p : {10, 12, 8, 4}
O/p : 1 (length is 1 because all elements are even and longest subarray chain is even only)

*/

#include<iostream>
#include<algorithm>
using namespace std;

int longestAlternatingChain(int arr[], int n)
{
    int res = 1,count = 1;
    for(int i=1; i<n; i++)
    {
        if((arr[i]%2==0 && arr[i-1]%2==0) || (arr[i]%2!=0 && arr[i-1]%2 !=0))
        {
            count = 1;
        }
        else
        {
            count++;
            res = max(res, count);
        }
    }
    return res;
}

int main(){
    int arr[] = {10, 11, 14, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = longestAlternatingChain(arr, n);
    cout<<val;
    return 0;
}
