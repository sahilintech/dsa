/*
Given an arr[] and sum. Return true if there exists a pair in array whose sum is equal to given sum

I/p : {3, 2, 8, 15, -8}
sum = 17

O/p : True(2+15=17)

Time= O(n)
Space= O(n)
*/

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool isPair(int arr[], int n, int sum)
{
    unordered_set <int> u;
    for(int i=0; i<n; i++)
    {
        if(u.find(sum-arr[i])!=u.end()) // sum-current element will return another element that form pair to sum of pair to be equal to given sum if it is true return true
        return true;
        else
        u.insert(arr[i]); // if current element does not form pair insert it in set , we are inserting elements one by one after checking because sum(6)-current element(3) can return true if all elements were inserted in one go and 3,3  pair is not present in array
    }
    return false;
}

int main(){
    int arr[] = {8, 3, 4, 2, 5};
    int sum = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isPair(arr, n, sum);
    return 0;
}