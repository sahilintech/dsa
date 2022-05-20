/*
Given a singly linkedlist. Delete the first node of linked list and return its new head

I/p : 10->20->30->40
O/p : 10->20->30

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

Node *delHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL) // if there is only one node
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL) // curr will stop at 2nd last node
        curr = curr->next;
    delete curr->next; // since address of last node is stored in curr->next deallocate that memory
    curr->next = NULL; // Pointing 2nd last node to Null;
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head = delHead(head);
    printList(head);
    return 0;
}