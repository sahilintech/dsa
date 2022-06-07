/*
Implement stack present in stl
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    cout << s.top() << endl;
    s.push(20);
    s.pop();
    cout << s.top() << endl; // gives first element
    cout << s.size() << endl;
    cout << s.empty() << endl; // returns 1 is stack is empty else 0
    return 0;
}