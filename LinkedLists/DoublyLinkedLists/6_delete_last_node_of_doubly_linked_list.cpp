/*
Given a doubly linked list . Delete last node of doubly linked list
I/p : 10
O/p : NULL

I/p : 10-><-20-><-30
O/p : 10-><-20

Time : O(n);
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node *delTail(Node *head)
{
    if (head == NULL) // if no node is present
        return NULL;
    if (head->next == NULL) // if only one node is present
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != NULL) // traversing upto 2nd last node
            curr = curr->next;
        curr->next->prev = NULL; // last node previous will become null
        curr->next = NULL; // 2nd last node next will become null
        delete curr->next; // deallocate last node
        return head;
    }
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    temp->prev = head;
    head->next = temp;
    temp->next = temp1;
    temp1->prev = temp;
    head = delTail(head);
    printList(head);
    return 0;
}