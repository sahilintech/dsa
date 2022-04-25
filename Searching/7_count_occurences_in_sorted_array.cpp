// Given a sorted array. Find the no. of occurences of given element in that array
/*
I/p : {10, 20, 20, 30, 30, 40}
    x = 20
O/p : 2 ( 20 occurs 2 times)

Idea is to find index of first and last occurence of element then 
No. of occurences = Lastocc. index - firstocc. index + 1

Time = O(log n)

*/

#include<iostream>
#include<algorithm>
using namespace std;

// Finding first occurence of given element
int FirstOcc(int arr[], int n, int ele)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < ele)
            low = mid + 1;
        else if (arr[mid] > ele)
            high = mid - 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid]) 
                return mid;
            else
                high = mid - 1;  
        }
    }
    return -1;
}

// Finding last occurence of given element
int LastOcc(int arr[], int n, int ele)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < ele)
            low = mid + 1;
        else if (arr[mid] > ele)
            high = mid - 1;
        else
        {
            if (mid == 0 || arr[mid] != arr[mid+1]) 
                return mid;
            else
                high = mid + 1;  
        }
    }
    return -1;
}

// Counting occurences of given element
int countOcc(int arr[], int n, int ele)
{
    int first = FirstOcc(arr, n, ele);
    if(first == -1)
        return 0; // Element not present zero occurences
    else
        return (LastOcc(arr, n, ele) - first + 1);
}

int main(){
    int arr[] = {10, 20, 20, 30, 30, 40};
    int ele = 40;
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = countOcc(arr, n, ele);
    cout<<ele<<" occurs "<<val<<" times";
    return 0;
}