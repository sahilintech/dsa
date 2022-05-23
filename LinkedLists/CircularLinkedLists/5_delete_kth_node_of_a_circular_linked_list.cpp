/*
Given a circular linked list and k . Delete kth node from circular linked list

I/p : <-10->20->30-> , k=2
O/p : <-10->30->

I/p : 10, k=1
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

Node *delKNode(Node *head, int k)
{
    if (head == NULL) // if ll is empty return NULL
        return head;
    if (k == 1) // if head has to deleted use previous approach to delete head
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
    Node *curr = head; // approach for deleting nodes other than head
    for (int i = 0; i < k - 2; i++)
        curr = curr->next;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
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
    int k = 1;
    head = delKNode(head, k);
    printList(head);
    return 0;
}