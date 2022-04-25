/*
******** Insertion Sort *************
Starting from second element insert these in correct position 

Time = theta(n^2)
Worst case = Reverse sorted array = theta(n^2)
Best case = Sorted array = theta(n)

*/

#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Element taken from unsorted part
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Moving elements to right side until we find the correct position of key
            j--;
        }
        arr[j + 1] = key; // Inserting key in correct position
    }
}

int main()
{
    int arr[] = {40, 26, 38, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}