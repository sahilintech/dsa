/*
Given two linked lists return the node where these two intersects

I/p : 5->8->7->10->12->15,  9->10->12->15
O/p : 10 (from node 10 linked list start intersecting)
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
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
// Function for counting both nodes
int getCount(Node *head)
{
    Node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    return count;
}

int getIntersection(int d, Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    for (int i = 0; i < d; i++)
    {
        if (curr1 == NULL)
            return -1;
        curr1 = curr1->next;
    }
    // now both ll has same no. of nodes after to which they are currently pointing
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int whichFuncToCall(Node *head1, Node *head2)
{
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    if (c1 > c2) // if first ll is longer call head1 first
    {
        int d = c1 - c2;
        return getIntersection(d, head1, head2);
    }
    else // else call head2 first because we are traversing longerlist in getIntersection first // the parameter which is passed first is traversed first so pass longer first
    {
        int d = c2 - c1;
        return getIntersection(d, head2, head1);
    }
}

int main()
{
    Node *newNode;

    Node *head1 = new Node(10);

    Node *head2 = new Node(3);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;
    cout << whichFuncToCall(head1, head2);
    return 0;
}