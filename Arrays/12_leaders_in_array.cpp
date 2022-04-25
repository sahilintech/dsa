// Given an array . Print the leaders of array. An element is called a leader is there not an equal or greater element present in right side of it
/*
I/p : {10, 2, 13, 4, 10, 12}
O/p : 13, 12

I/p : {7,10,4,10,6,5,2}
O/p : 10, 6, 5, 2
*/

#include <iostream>
using namespace std;

void printLeaders(int arr[], int n)
{
    int currLeader = arr[n-1];  //Last element is always a leader
    cout<<currLeader<<" "; 
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i]>currLeader)
        {
            cout<<arr[i]<<" ";  
            currLeader = arr[i]; // Updating currLeader
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}