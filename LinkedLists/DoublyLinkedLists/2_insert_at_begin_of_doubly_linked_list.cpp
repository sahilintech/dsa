/*
Given a doubly linked list and value x,  insert x at begining of linked list

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

Node *insertAtBegining(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head; // next of new node will contain address of head
    if (head != NULL) // if head is null then no need to change its previous 
        head->prev = temp; // previous of previous head will contain address of new head only if linked list is not empty
    return temp; // return new head
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
    head->prev = NULL;
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    int data = 20;
    head = insertAtBegining(head, data);
    printList(head);
    return 0;
}