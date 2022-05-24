/*
Given a linked list. Reverse it
I/p : 10->20->30->40
O/p : 40->30->20->10

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

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *temp = curr->next; // will help in loop through
        curr->next = prev; // previous contains address of one element less than curr
        prev = curr; // make previous as curr then update curr
        curr = temp; // update curr
    }
    return prev; // return prev  as at last prev will point to last element and current to null
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
    head->next->next->next->next = new Node(50);
    head = reverse(head);
    printList(head);
    return 0;
}
