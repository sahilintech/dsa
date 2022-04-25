#include <bits/stdc++.h>
using namespace std;

struct MyHash
{
    int *arr; // Taking a pointer array to store the keys
    int cap, size;

    MyHash(int c)
    {
        cap = c; // Capacity of array will be initialized by MyHash constructor
        size = 0; // Currently array is not filled so size is taken as zero
        arr = new int[cap];
        for (int i = 0; i < cap; i++)
            arr[i] = -1;  // -1 is taken to indicate that array is empty
    }
    int hash(int key)
    {
        return key % cap; // Hash function calculating
    }
    bool insert(int key)
    {
        if (size == cap) // If array is full while inserting return false
            return false;
        int i = hash(key); // Generating hash and storing in i
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key) // while array is not empty or array index is not deletd of array element is not equal to key increment i by linear probing
            i = (i + 1) % cap;
        if (arr[i] == key) // if we found same element on array as key we do not want to insert same elements
            return false;
        else // if array index is empty or was deleted fill it with the key
        {
            arr[i] = key; 
            size++; // increase current size of array
            return true;
        }
    }

    bool search(int key)
    {
        int h = hash(key); 
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;
            i = (i + 1) % cap; // increment i if above function does not return true
            if (i == h) // if we came back to same index while searching return false means we did not find the element
                return false;
        }
        return false;
    }

    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key) // if key is found delete it and to mark it as deleted make that index = -2
            {
                arr[i] = -2; 
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
};

int main()
{
    MyHash mh(7);
    mh.insert(49);
    mh.insert(51);
    mh.insert(62);
    if (mh.search(51) == true)
        cout << "Yes\n";
    else
        cout << "NO\n";
    mh.erase(51);
    if (mh.search(51) == true)
        cout << "Yes\n";
    else
        cout << "NO\n";
    return 0;
}