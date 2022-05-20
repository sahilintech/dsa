/*
Given a doubly linked list and value x,  insert x at end of linked list

I/p : 10->20->30, x=5

O/p : 5->10->20->30

Time : O(1)
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

Node *insertAtEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL) // If ll is empty simply return newly create node
        return temp;
    Node *curr = head;
    while (curr->next != NULL) // if ll is not empty traverse till last node
        curr = curr->next;
    curr->next = temp; // last node next should contain address of new node
    temp->prev = curr; // new node prev should contain address of last node
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
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    int data = 40;
    head = insertAtEnd(head, data);
    printList(head);
    return 0;
}