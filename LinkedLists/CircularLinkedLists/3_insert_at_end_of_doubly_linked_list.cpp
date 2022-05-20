/*
Given a doubly linked list and data . Insert the data at end of doubly linked list

I/p : <-10->20->30->, data = 40
O/p : <10->20->30->40->

I/p : NULL , data = 5
O/p : <-5->

****************** Naive : O(n) ***********************
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

Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
 
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
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
    int data = 5;
    head = insertEnd(head, data);
    printList(head);
    return 0;
}

*/

// Efficient O(1);
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

Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    // simply swap data of both head and temp after linking temp with head and with address stored in head->next
    else
    {
        temp->next = head->next;
        head->next = temp;
        swap(head->data, temp->data);
        return temp; // trick is same as insert in begining but here we are returning second node as head i.e temp
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
    int data = 5;
    head = insertEnd(head, data);
    printList(head);
    return 0;
}
