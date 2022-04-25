#include <iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int temp, low = 0, high = n - 1;
    while (low < high)
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
}

int main()
{
    int arr[] = {10, 40, 30, 5, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before reversing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"\n";
    reverse(arr, n);
    cout << "After reversing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}