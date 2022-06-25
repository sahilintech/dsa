#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

queue<int> q1;
queue<int> q2;
struct MyStack
{
    int sz;
    MyStack()
    {
        sz = 0;
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q2;
        q2 = q1;
        q1 = q;
        sz++;
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        sz--;
    }

    int size()
    {
        return sz;
    }

    int top()
    {
        if (q1.empty())
            return INT_MAX;
        return q1.front();
    }
};
int main()
{
    MyStack s;
    s.push(10);
    s.push(5);
    s.push(15);
    s.push(20);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size() << endl;
}