/*
*********** Bubble Sort *************
 Compares adjacent elements and moves elements to last place starting from greater one
 It is a stable algorithm
No. of passes = n-1
Time : O(n^2)
Time for sorted array : O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {40, 26, 38, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}