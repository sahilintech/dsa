// Find the maximum difference of given array. Maximum value of arr[j] - arr[i] such that j>i
// This above means that arr[j] should be in right side of arr[i];
/*
I/p : {2, 3, 10, 6, 4, 8, 1}
O/p : 10 - 2 i.e 8

I/p : {30, 10, 8, 2}
O/p : 8-10 i.e -2
*/

#include<iostream>
#include<algorithm>
using namespace std;

void maxDiff(int arr[], int n)
{
    int res = arr[1] - arr[0];
    int minVal = arr[0];
    for(int j=1; j<n; j++)
    {
        res = max(res, arr[j]-minVal);
        minVal = min(arr[j], minVal);
    }
    cout<<res;
}

int main(){
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxDiff(arr, n);
    return 0;
}