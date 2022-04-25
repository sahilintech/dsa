// Given a array. Return the minimum difference between any two elements of array
/*
I/p : {1, 8, 12, -1}
O/p : -13

*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minimumDifference(int arr[], int n)
{
    sort(arr, arr+n);
    int res = INT_MAX; // if there is only one element return infinity
    for(int i=1; i<n; i++)
    {
        res = min(res, (arr[i]-arr[i-1]));
    }
    return res;
}

int main(){
    int arr[] = {-2, 8, 12, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minimumDifference(arr, n);
    return 0;
}