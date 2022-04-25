/*
Cycle sort widely used where you have to count no. of swaps and it also does less write in disk

For every element count how many elements are smaller than that element then fix the current element at index which is equal to count of smaller elements

I/p : {20, 40, 50, 10, 30}

O/p : {10, 20, 30, 40, 50}

Time : O(n2);
*/

#include <iostream>
#include <algorithm>
using namespace std;

void cycleSort(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs]; // see elements which are smaller than item(i.e current element)
        int pos = cs;       // There are cs elements smaller than item if cs will become 1 then pos will also become 1 because 1st element will be fixed at its correct position
        for (int i = cs + 1; i < n; i++)
            if (arr[i] < item)
                pos++; // count how much elements are smaller than current element
        swap(item, arr[pos]);

        // while loop for completing cycle
        while (pos != cs) // if pos == cs it means element is already at its correct position
        {
            pos = cs; // again initialize pos as cs
            for (int i = cs + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;
            swap(item, arr[pos]);
        }
    }
}

int main()
{
    int arr[] = {20, 40, 50, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
    for (int i : arr)
        cout << i << " ";
    return 0;
}