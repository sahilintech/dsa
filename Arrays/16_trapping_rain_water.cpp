// Find the water that can be collected inside element blocks of array. See copy or google can't be explained in vs code

/*
I/p : {2, 0, 2}
O/p : 2

I/p : {3, 0, 1, 2, 5}
O/p : 6

Time = O(n)
Space = theta(n)

*/

#include <iostream>
#include <algorithm>
using namespace std;

int waterCollected(int block[], int n)
{
    int res = 0;
    int *lMax = new int[n];
    int *rMax = new int[n];
    lMax[0] = block[0];
    rMax[n - 1] = block[n - 1];
    for (int i = 1; i < n; i++)
        lMax[i] = max(block[i], lMax[i - 1]); // Checking if current block is lMax 
    for (int i = 1; i < n - 1; i++)
        rMax[i] = max(block[i], rMax[i - 1]); // Checking if current block is rMax
    for (int i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - block[i]);
    return res;
}

int main()
{
    int block[] = {3, 0, 1, 2, 5};
    int n = sizeof(block) / sizeof(block[0]);
    int res = waterCollected(block, n);
    cout << res;
    return 0;
}