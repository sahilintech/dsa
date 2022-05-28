/*
Swap two consecutive nodes of linked list
I/p : 1->2->3->4->5->6
O/p : 2->1->4->3->6->5

I/p : 1->2->3->4->5
O/p : 2->1->4->3->5

Time : O(n)
// Method 1 => Swapping data,  Time : O(n)
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

void pairwiseSwap(Node *head)
{
    // simply swap the data
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
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
    pairwiseSwap(head);
    printList(head);
    return 0;
}

*/

// Method 2 => Changing Links, Time : O(n)

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

Node *pairwiseSwap(Node *head)
{
    if(head == NULL || head->next == NULL)
    return head;
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while(curr!=NULL && curr->next!=NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node*temp = curr->next->next;
        curr->next->next = curr;
        curr = temp;
    }
    prev->next = curr;
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
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head = pairwiseSwap(head);
    printList(head);
    return 0;
}