// Deletion of given element in array

#include <iostream>
using namespace std;

int deletion(int arr[], int n, int element)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
            break;
    }
    if (i == n) // If element is not present then i will retain its previous value and become n and we will return same size of array.
        return n; // returning n means element is not present

    for (int j = i; j < n-1; j++)
    {
        arr[j] = arr[j + 1]; // Shifting occurs due to deletion one space is empty
    }
    return n - 1; // n-1 means size is decreased i.e element was present and now deleted due to which size is decrease
}

int main()
{
    int n, element;
    cout << "Enter size of array\n";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to be deleted\n";
    cin >> element;
    int l = deletion(arr, n, element);
    for (int i = 0; i < l; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}