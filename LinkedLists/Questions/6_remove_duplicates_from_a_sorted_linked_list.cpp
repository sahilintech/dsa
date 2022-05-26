/*
Given a sorted linked list. Remove duplicates from it

I/p : 10->20->20->30->30->30
O/p : 10->20->30

I/p : NULL
O/p : NULL
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

void removeDuplicates(Node *head)
{
    Node *curr = head;
    while (curr!=NULL && curr->next != NULL) // first condition is given because head can also be NULL
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next->next; // store the address of node->next which is to be removed
            delete curr->next; // delete node
            curr->next = temp; // put stored address in curr->next for linking
        }
        else 
            curr = curr->next; // Traverse only while curr->data != curr->next->data because we can have multiple duplicates
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
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    removeDuplicates(head);
    printList(head);
    return 0;
}