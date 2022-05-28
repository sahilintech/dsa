/*
Given a linked list . If there is loop in it then remove it

Time : O(n)
Space : O(1)
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

void removeLoop(Node *head)
{
    Node *slow = head, *fast = head;
    // detect loop
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) // first meeting break
            break;
    }
    if (fast != slow) // check if break really occured due to meeting point or NULL
        return;
    while (fast->next != slow->next) // find previous node of 2nd meeting point because previous node will help in removing loop by making fast->next = NULL
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    removeLoop(head);
    return 0;
}