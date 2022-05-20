/*
/*
Given a circular linked list and data . Insert the data at begining of circular linked list

I/p : <-10->20->30->, data = 40
O/p : <-40->10->20->30->

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

Node *insertBegin(Node *head, int data)
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
    head = insertBegin(head, data);
    printList(head);
    return 0;
}