/*
Given an array count no. of distinct elements in it do not count same elements

I/p: [15, 12, 13, 12, 13, 13, 18]
O/p : 4

Time = 0(n) // Every element is checked by unordered set whether to store it or not
Space = O(n) // Here O is used because if all elements are same then aux space will be O(1)
*/

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int countDistinctElements(int arr[], int n)
{
    unordered_set <int> s(arr, arr+n); // Since unordered set will not store duplicate element so its size is the answer
    return s.size();
}
int main(){
    int arr[] = {15, 12, 13, 12, 13, 13, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countDistinctElements(arr, n);
    return 0;
}