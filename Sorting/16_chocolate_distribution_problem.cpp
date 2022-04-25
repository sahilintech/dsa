/*
Given an array of chocolates. If size of array is 7. There are 7 packets of chocolates. Every element gives the no. of chocolates contained in that packet. Also given m (no. of children)

I.p = {7, 3, 2, 4, 9, 12, 56}
    m = 3

O/p : 2 (Difference)

Rule 1 : Every child should get exactly one packet
Rule 2 : Minimize the difference between minimum chocolates a child gets and maximum chocolates that another child gets

Time : O(n logn)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int distributeChocolates(int arr[], int n, int m)
{
    if(m>n) return -1; // No. of children are greater than packets (i.e size of array)
    sort(arr, arr+n);
    int res = arr[m-1] - arr[0]; // for i=0 calculated difference of third and 1st element if children are three.
    for(int i=1; i<=n-m; i++)
    {
        res = min(res, (arr[m+i-1] - arr[i]));
    }
    return res;
}

int main(){
    int arr[] = {7, 9, 12, 56, 4, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 3; //No. of children
    cout<<distributeChocolates(arr, n, m);
    return 0;
}