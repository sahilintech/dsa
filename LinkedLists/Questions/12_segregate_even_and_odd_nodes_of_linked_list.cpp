/*
Given a linked list. Edit the linked list such that all even nodes come first and then all odd ones

I/p : 17->15->8->12->10->5->4
O/p : 8->12->10->4->17->15->5

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

Node *segregateEvenAndOdd(Node *head)
{
    // here es = evenStart, ee = evenEnd ....
    Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->data;
        if (x % 2 == 0) // if curr->data is even
        {
            if (es == NULL) // first node of even ll initialized
            {
                es = curr;
                ee = es;
            }
            else // adding other than first nodes to even ll
            {
                ee->next = curr;
                ee = ee->next;
            }
        }
        else // add nodes to odd ll
        {
            if (os == NULL)
            {
                os = curr;
                oe = os;
            }
            else
            {
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if (es == NULL || es == NULL) // if we are either only having even or only all odd nodes then we can't link them
        return head;              // if same type of nodes simply return head
    ee->next = os;                // else link evenEnd with oddStart
    oe->next = NULL;              // make oddEnd as NULL
    return es;                    // return evenStart
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
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next = new Node(10);
    head->next->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head = segregateEvenAndOdd(head);
    printList(head);
    return 0;
}
