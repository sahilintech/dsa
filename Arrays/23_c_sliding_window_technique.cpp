// Print first M, N - bonacci number

/*
I/p : N=3, M=8
Means we need to print first 8 , 3-bonacci numbers 
3-bonnaci numbers means every element is found using sum of its previous 3 elements.

O/p : 0, 0, 1, 1, 2, 4, 7, 13

Time: O(M)
*/

#include <iostream>
#include <algorithm>
using namespace std;

void printNbonacci(int n, int m)
{
    int a[m] = {}; // Means every element is initialize with zero
    a[n - 1] = 1;  // Every bonnaci will contain two ones
    a[n] = 1;
    for (int i = n + 1; i < m; i++)
        a[i] = 2 * a[i - 1] - a[i - n - 1];
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
}

int main()
{
    int N, M;
    N = 3;
    M = 8;
    printNbonacci(N, M);
    return 0;
}