/*
Given a linked list. Reverse it using recursion
I/p : 10->20->30->40
O/p : 40->30->20->10

Time : O(n)
Space : O(n)

******************* First Approach **********************
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

Node *recursiveReverse(Node *head)
{
    if (head == NULL || head->next==NULL)
        return head;
    Node *restHead = recursiveReverse(head->next); // this will reverse the linked list links upto 20
    Node *tailHead = head->next; // obtain address of 20
    tailHead->next = head; // 20 should be linked to 10
    head->next = NULL; // 10->next = NULL
    return restHead; // restHead i.e 50 was returned by recursiveReverse
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
    head = recursiveReverse(head);
    printList(head);
    return 0;
}
*/

//********************** 2nd Approach *******************
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

Node *recursiveReverse(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;
    Node *temp = curr->next; // Linking nodes
    curr->next = prev;
    recursiveReverse(temp, curr); // curr is passed as current next, prev is passes as current
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
    head = recursiveReverse(head, NULL);
    printList(head);
    return 0;
}