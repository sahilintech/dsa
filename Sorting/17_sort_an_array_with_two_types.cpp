/*
Sort an array with two types
Given an array containing positive and negative elements put negative elements first and then positive in any order

I/p : {15, -3, -2, 18}
O/p : {-3, -2, 18, 15};

Time : 0(n)
Space: O(1)

*/

#include<iostream>
#include<algorithm>
using namespace std;

void sortTwoTypesArray(int arr[], int n)
{

    int pivot = arr[n-1];
    int j=0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], pivot);
}

int main(){
    int arr[] = {15, -3, -2, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortTwoTypesArray(arr, n);
    for(int i: arr)
    cout<<i<<" ";
    return 0;
}