/* Rules
1) Only one disc at a time
2) No larger disc above smaller
3) Only the top disc of a tower can be moved.

I/p : n=3 i.e no. of discs
O/p : Move disc 1 from A to C
    : Move disc 2 from A to B
    : Move disc 1 from C to B
    : Move disc 3 from A to C
    : Move disc 1 from B to A
    : Move disc 2 from B to C
    : Move disc 1 from A to C

*/
#include <iostream>
#include <typeinfo>
#define ll int; // Every int will become long long int
using namespace std;
int moves = 0;
void toh(int n, char source, char auxillary, char destination)
{
    moves++;
    if (n == 1)
    {
        cout << "Move " << n << " from " << source << " to " << destination << endl;
        return;
    }
    // It will call (1, A, C, B) because source has A , destination has C and aux has B in it
    toh(n - 1, source, destination, auxillary);
    cout << "Move " << n << " from " << source << " to " << destination << endl;
    toh(n - 1, auxillary, source, destination);
}

int main()
{
    long long int n;
    cout << "Enter no. of discs" << endl;
    cin >> n;
    toh(n, 'A', 'B', 'C');
    cout << moves << " moves taken" << endl;
    return 0;
}


