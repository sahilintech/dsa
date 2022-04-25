// Quick sort . partition elements such that element on left side are less than elements on right side using hoare partition and sort form 0 to returned index and returned index + 1 to high

#include <iostream>
#include <algorithm>
#include "0_header.h"
using namespace std;

void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int returnedIndex = hoarePartition(arr, low, high);
        quickSort(arr, low, returnedIndex);
        quickSort(arr, returnedIndex+1, high);
    }
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i=0; i<7; i++)
        cout << arr[i] << " ";
    return 0;
}