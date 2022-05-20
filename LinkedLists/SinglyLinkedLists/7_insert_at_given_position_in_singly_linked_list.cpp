/*
Given a singly linked list and a position and data. Insert the data at given position in singly linked list

I/p : 10->20->30->40, pos=3, data=15
O/p : 10->20->15->30->40

I/p : NUll , pos=1, data=10
O/p : 10

Time : O(pos)
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

Node *insertAtPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    if (pos == 1) // if head is NULL or we want to change head
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2; i++) // iterate two position less
        curr = curr->next;
    if (curr == NULL) // for cases if pos is 5 and linked has size of 3 we can't insert
        return head;
    temp->next = curr->next;
    curr->next = temp;
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
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(60);
    int pos = 3, data = 30;
    head = insertAtPos(head, pos, data);
    printList(head);
    return 0;
}