/*
Implement min heap
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return ((i - 1) / 2);
    }

    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[i] < arr[parent(i)];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i) // Time : O(log n)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin() // Time: O(log n)
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }

    void decreaseKey(int i, int x) // O(log n)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) // O(logn)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void buildHeap() // O(n)
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
            minHeapify(i);
    }
};

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.extractMin() << endl;
    return 0;
}