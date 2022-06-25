/*
Implement stack using linked list
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }
    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return head->data;
    }
    int size()
    {
        return sz;
    }
    int isEmpty()
    {
        return (head == NULL);
    }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(3);
    cout << s.peek() << endl;
    cout << s.size() << endl;
    s.push(4);
    s.pop();
    cout << s.peek() << endl;
    return 0;
}