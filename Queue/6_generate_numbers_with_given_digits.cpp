/*
Given a number n, put first n numbers in increasing order such that all these numbers have digits in set {5,6}

I/p : n = 10, set = {5,6}
O/p : 5, 6, 55, 56, 65, 66, 555, 556, 565, 566

I/p : n=4, set = {6, 7}
O/p : 6, 7, 66, 67
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

void generateNumbers(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < n; i++)
    {
        string curr = q.front();
        cout << curr << " ";
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{
    int n = 5;
    generateNumbers(5);
    return 0;
}