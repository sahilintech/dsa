/*
Implement stack using array and constructor
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow";
            return INT_MIN;
        }
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow";
            return INT_MIN;
        }
        return arr[top];
    }
    int size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    MyStack s(5);
    s.push(1);
    s.push(2);
    cout << s.peek() << endl;
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}