/*
Given an array and a var k. Print k largest elements from array.
Time : O(n+k)
Space : O(n + klogn) // For pq
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// Time : O(n+klogn) efficient sol
/*
void printKLargestElements(int arr[], int n, int k)
{
    priority_queue<int> pq(arr, arr+n);
    for(int i=0; i<k; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
*/

// Time: O(k+(n-k)logk) More efficient solution
void printKLargestElements(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) // O(k)
        pq.push(arr[i]);

    for (int i = k; i < n; i++) // O((n-k)logk)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
        else
            continue;
    }
    while (pq.empty() == false) // O(k)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {8, 6, 4, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKLargestElements(arr, n, k);
    return 0;
}