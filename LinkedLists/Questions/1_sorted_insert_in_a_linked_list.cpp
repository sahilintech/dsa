/*
Given a sorted linked list and a data. Insert the data in linked list in such a way that it remains sorted

I/p : 10->20, data = 30
O/p : 10->20->30

I/p : NUll, data = 5
O/p : 5

I/p : 10->20, data = 5
O/p : 5->10->20

Time : O(n)
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

Node *insertNode(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL) // if ll is empty add a new node
        return temp;
    if (data < head->data) // if data is to be inserted at first position handle it separately
    {
        temp->next = head; // linking head node with new head node
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < data) // traversing upto element smaller than data
        curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    return head;
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
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);
    int data = 60;
    head = insertNode(head, data);
    printList(head);
    return 0;
}