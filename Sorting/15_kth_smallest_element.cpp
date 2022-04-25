/*
Given an array and value of k . Return the element which is at the kth position.
*/

#include<iostream>
#include<algorithm>
#include "0_header.h"
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    int l = 0;
    int h = n-1;
    while(l<=n)
    {
        int p = lomutoPartition(arr, l, h);
        if(p == k-1)
            return arr[p];
        else if(p>k-1)
            h = p-1;  // if element to be found is smaller than pivot returned by lomuto partition then search on left side and vice versa
        else
            h = p+1;
    }
    return -1; // Element not present
}

int main(){
    int arr[] = {30, 40, 1 , 56, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<kthSmallest(arr, n, k);
    return 0;
}