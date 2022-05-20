/*
Given a singly linked list and value x,  insert x at end of linked list

I/p : 10->20->30, x=5

O/p : 10->20->30->5

Time : O(1) for insertEnd function if pointer to last node is given
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

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL) // if list is empty then make temp as head
        return temp;

    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp; // new address is assigned to last node instead of null
    return head;  // if list is not empty head should be returned as same
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
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);
    return 0;
}