/*
******** Selection Sort *************
Find the smallest element from array and swap it with first element, then from remaining array again find min element and swap with second element and so on

Time = theta(n^2)

*/

#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap (arr[min_ind], arr[i]);
    }
}

int main()
{
    int arr[] = {40, 26, 38, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}