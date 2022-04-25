// Given a group of people(value of) in circle. Kill every kth person and hand over the gun to next. Output the last man survived

#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 0; // always 0th person will be survived if there is 1 person
    else
        return (josephus(n - 1, k) + k);
}

int main()
{
    int n, k;
    cout << "Enter no. of people" << endl;
    cin >> n;
    cout << "Enter the kth value" << endl;
    cin >> k;
    int j = josephus(n, k);
    cout << j + 1 << "th person survived"; // Actually person will start from 1
    return 0;
}