// Search required element in unsorted array and return its positon else not found return -1

#include<iostream>
using namespace std;

int search(int arr[], int n, int k)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == k)
        return i;
    }
    return -1;
}

int main(){
    int n, k;
    cout<<"Enter size of array\n";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements of array\n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>k;
    cout<<"Element is at index "<<search(arr, n, k);
    return 0;
}