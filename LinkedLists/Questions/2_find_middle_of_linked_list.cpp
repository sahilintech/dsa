/*
Given a singly linked list. Find the middle of linked list and print it

I/p : 10->5->20->15->25
O/p : 20

I/p : 10->5->20->15->25->30
O/p : 15

I/p : NULL
O/p : NULL

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

void findMiddle(Node *head)
{
    if (head == NULL)
        return;
    Node *slow = head, *fast = head;
    // move fast pointer 2 times than slow 
    while (fast != NULL && fast->next != NULL) // two conditions in while for handling both even and odd no. of nodes
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    findMiddle(head);
    return 0;
}