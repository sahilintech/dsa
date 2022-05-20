/*
Given a doubly linked list . Delete its head and return new head
I/p : 10
O/p : NULL

Time : O(1);
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

Node *delHead(Node *head)
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
        Node *temp = head->next; // 2nd node address is saved so that we can return it as head
        head->next->prev = NULL; // 2nd node prev will become null if it has to become head
        head->next = NULL; // curr head->next should become null
        delete head; // delete curr head
        return temp; // return new head
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
    head = delHead(head);
    printList(head);
    return 0;
}