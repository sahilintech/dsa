/*
Radix Sort = sort every digit of array starting from last digit to most significant digit. At last you will have sorted array in your hands

I/p : {319, 212, 6, 8, 100, 50}

O/p : {6, 8, 50, 100, 212, 319} / 6 will be considered as 006...

Time : 0(d*(n+b)) where b is size of temp array which will be always 10 because every digit will range from 0 to 10 and d is max no. of digits in max element
Space : 0(n+b)

*/

#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    // Creating temp array of size 10 because in an element a single digit will vary only from 0 to 9
    int temp[10] = {0}; // Initialize elements as 0;
    // Increment values of temp according to elements of arr
    for (int i = 0; i < n; i++)
        temp[(arr[i] / exp) % 10]++;
    // Find cumulative sum it indicates that corresponding element of arr should positioned as element of temp i.e if arr[0] is 9 and temp[0] = 4 then 9 should have index 3 is main array.
    for (int i = 1; i < 10; i++)
        temp[i] = temp[i] + temp[i - 1];
    // Create new array to store elements according to their position
    int *output = new int[n];
    // Position elements of arr according to elements of temp
    for (int i = n - 1; i >= 0; i--)
    {
        output[temp[(arr[i] / exp) % 10] - 1] = arr[i];
        temp[(arr[i] / exp) % 10]--;
    }
    // Copy output array to main array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n)
{
    // Find the max element in the array.
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    // Now find how many digits that max element has and call counting sort for that every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {319, 212, 6, 8, 100, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}