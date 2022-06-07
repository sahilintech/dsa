/*
Given two linked lists in sorted order. Merge both such that the remaining linked list also remains sorted

I/p : a = 10->20->30->40
      b = 5->25

O/p : 5->10->20->25->30->40

I/p : a = 10->20
      b = NULL

O/p : 10->20

Time : O(m+n), Space: O(1)
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

Node *mergeSortedLists(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)  // if any of linked list is null simply return another linked list
        return head1 == NULL ? head2 : head1;

    Node *newHead = NULL, *tail = NULL;
    if (head1->data < head2->data) // checking which node is smaller from both linked list to initialize resultant head
    {
        newHead = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        tail = head2;
        head2 = head2->next;
    }
    while  (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data) // if head1 node is smaller link tail of newnode with it and do update tail and head1
                {
                    tail->next = head1;
                    tail = head1;
                    head1 = head1->next;
                }
            else
            {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
    if (head1 != NULL) // if any linked list is larger link new ll with this larger linked list
        tail->next = head1;
    else
        tail->next = head2;
    return newHead;
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
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);
    head1->next->next->next->next = new Node(50);
    Node *head2 = new Node(5);
    head2->next = new Node(25);
    Node *newHead = mergeSortedLists(head1, head2);
    printList(newHead);
    return 0;
}