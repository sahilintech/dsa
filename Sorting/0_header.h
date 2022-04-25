#include<iostream>
using namespace std;

void mergeFunction(int arr[], int low, int mid, int high)
{
    int l = mid - low + 1;
    int h = high - mid;
    int *left = new int[l];
    int *right = new int[h];
    for (int i = 0; i < l; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < h; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < l && j < h)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < l)
        arr[k++] = left[i++];
    while (j < h)
        arr[k++] = right[j++];
}

int lomutoPartition(int arr[], int low, int high)
{
  //swap(arr[pivot], arr[high]) if pivot is not last element and user enter any index for pivot element then swap last and pivot element then proceed.
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}