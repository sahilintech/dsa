/*
Given a circular linked list. Delete the head of circular linked list

I/p : <-10->20->30->
O/p : <-20->30->

I/p : NULL
O/p : NULL

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
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp = head->next->next;
        swap(head->data, head->next->data);
        delete head->next;
        head->next = temp;
        return head;
    }
}

void printList(Node *head)
{
    if (head == NULL)
        return;
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = delHead(head);
    printList(head);
    return 0;
}
