/*
Given a singly linkedlist. Delete the first node of linked list and return its new head

I/p : 10->20->30->40
O/p : 20->30->40

I/p : NULL
O/p : 

Time : O(1)
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
    if (head == NULL) // if list is empty
        return NULL;
    else
    {
        Node *temp = head->next; // address of 2nd node is stored in temp
        delete head; // deallocation of first node
        return temp; // address of 2nd node is retured and taken as head in main function
    }
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