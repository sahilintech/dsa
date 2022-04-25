// Insert the given element in array at given position

#include<iostream>
using namespace std;

int insert(int arr[], int n, int element, int pos)
{
    int index = pos-1; 
    for(int i=n-1; i>=index; i--)
    {
        arr[i+1] = arr[i]; // Shifting array so that position should be empty for upcoming element
    }
    arr[index] = element;
    return n+1;
}

int main(){
    int n, element, pos;
    cout<<"Enter size of array\n";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements of array\n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be inserted\n";
    cin>>element;
    cout<<"Enter the position where element is to be inserted\n";
    cin>>pos;
    int l = insert(arr, n, element, pos);
    for(int i=0; i<l; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}