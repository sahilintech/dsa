/*
Given two arrays . Find the count of element that form union

I/p : a[]= {15, 20, 5, 15}
      b[]= {15, 15, 15, 20, 10}

O/p : 4

Time: 0(n)
Space: O(n1+n2)
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int countUnions(int arr1[], int arr2[], int n1, int n2)
{
    // Insert both arrays in same set and return its size which will give the count of union
    unordered_set <int> s(arr1, arr1+n1);
    for(int i=0; i<n2; i++)
    s.insert(arr2[i]);
    return s.size();
}

int main()
{
    int arr1[] = {10, 10, 10};
    int arr2[] = {10, 10, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << countUnions(arr1, arr2, n1, n2);
    return 0;
}