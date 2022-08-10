/*
Given an array and a var k, x. Find the k no. of elements which are closest to var x
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;


void printKClosestElements(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<k; i++)
        pq.push({abs(arr[i]-x), i});
    for(int i=k; i<n; i++)
    {
        auto j = pq.top();
        if(j.first>abs(arr[i]-x))
        {
            pq.pop();
            pq.push({abs(arr[i]-x), i});
        }
    }
    while(pq.empty()==false)
    {
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 30, 5, 40, 38, 80, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 35, k = 3;
    printKClosestElements(arr, n, k, x);
    return 0;
}