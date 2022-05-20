/*
Given a linked list. Traverse the linked list and print the data using recursion

I/p : |10| |->|20| |->|30| |->|40|Null|

O/p : 10, 20, 30, 40

Time : O(n)
Space : O(n)
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

void recursivePrintList(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    recursivePrintList(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    recursivePrintList(head);
    return 0;
}