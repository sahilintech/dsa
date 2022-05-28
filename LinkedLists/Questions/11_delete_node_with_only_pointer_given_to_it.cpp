/*
Given a linked list and pointer to the node which is to be deleted. Delete that nod
Note = Node to be deleted will never be last node

I/p : 10->20->30->40 , d = 30
O/p : 10->20->40

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

void delNode(Node *node)
{
    if (node == NULL || node->next == NULL)
        return;
    node->data = node->next->data; // make data of curr node same as next node and delete next node
    Node *temp = node->next;
    node->next = node->next->next;
    delete temp;
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
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    delNode(head->next);
    printList(head);
    return 0;
}