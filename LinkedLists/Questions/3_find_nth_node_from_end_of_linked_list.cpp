/*
Given a linked list. Find the nth node from end of linked list

I/p : 10->20->30->40, n=2
O/p : 30

I/p : 10->20->30, n=4
O/p : ---

Time : O(n)
*/

#include <iostream>
#include <algorithm>
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

void findNodeFromEnd(Node *head, int n)
{
    if (head == NULL)
        return;
    // Move first pointer upto nth position starting from head then run it to null and move 2nd pointer from head and print 2nd data.
    Node *first = head, *second = head; 
    for (int i = 0; i < n; i++)
    {
        if (first == NULL)  // if n will be greater than no. of nodes this condition can invoke
            return;
        first = first->next;
    }
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << second->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    findNodeFromEnd(head, 2);
    return 0;
}