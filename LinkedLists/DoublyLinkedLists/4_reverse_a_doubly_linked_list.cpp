/*
Given a doubly linked list. Reverse the linked list and return its new head

I/p : 10-><-20-><-30
O/p : 30-><-20-><-10
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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = NULL, *curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // as we are swapping next and prev , now prev will contain address of next node so curr->prev
    }
    return temp->prev; // at last temp will contain address of 2nd node and doing temp->prev will give us new head
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
    head = reverse(head);
    printList(head);
    return 0;
}