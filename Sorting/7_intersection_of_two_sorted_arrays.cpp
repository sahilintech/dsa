// Print common elements between two sorted arrays 
/*
I/p: a[] = {1, 1, 3, 3, 3}
    b[] = {1, 1, 1, 1, 3, 5, 7}

O/p = 1, 3

Time : O(m+n)
Space: O(1)
*/


#include <iostream>
#include <algorithm>
using namespace std;

void intersectedArray(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
}

int main()
{
    int arr1[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int arr2[] = {5, 10, 10, 15, 30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    intersectedArray(arr1, arr2, n1, n2);
    return 0;
}