/*
Given an array which is nearly sorted

Time : O(n+klogk
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void sortKSortedArray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int index = 0;
    for (int i = 0; i <= k; i++) // first push k items = O(k logk)
        pq.push(arr[i]);
    for(int i=k+1; i<n; i++) // then push remaing items and simultaneuly sort array O((n-k)*logk)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(pq.empty() == false) // take out remaining items // O(klogk)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
    
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {9, 8, 7, 18, 19, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    sortKSortedArray(arr, n, k);
    printArray(arr, n); 
    return 0;
}