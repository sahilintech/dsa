#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
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

struct MyQueue
{
    Node *front, *rear;
    int sz;
    MyQueue()
    {
        front = rear = NULL;
        sz = 0;
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (rear == NULL)
        {
            front = rear = temp;
            sz++;
            return;
        }
        rear->next = temp;
        rear = temp;
        sz++;
    }

    void dequeue()
    {
        if (front == NULL)
            return;
        Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        sz--;
    }

    int size()
    {
        return sz;
    }
};

int main()
{

    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.size()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.size()<<endl;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.size()<<endl;
    q.dequeue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}
