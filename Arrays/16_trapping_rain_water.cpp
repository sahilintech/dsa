// Find the water that can be collected inside element blocks of array. See copy because whole google can't be explained in vs code

/*
I/p : {2, 0, 2}
O/p : 2

I/p : {3, 0, 1, 2, 5}
O/p : 6

Time = O(n)
Space = theta(n)


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

*/

// More optimal solution (Time: O(n), Space: O(1))
// Two pointer approach

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;

int waterCollected(int block[], int n)
{
    int low = 1, high = n - 2;
    int lmax = block[0], rmax = block[n - 1];
    int res = 0;
    while (low <= high)
    {
        if (lmax < rmax)
        {
            if (block[low] > lmax)
                lmax = block[low];
            else
                res += lmax - block[low];
            low++;
        }
        else
        {
            if (block[high] > rmax)
                rmax = block[high];
            else
                res += rmax - block[high];
            high--;
        }
    }
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