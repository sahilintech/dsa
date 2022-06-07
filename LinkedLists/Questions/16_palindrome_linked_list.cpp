/*
Given a linked list. Check if a is palindrome or not

I/p : R->A->D->A->R
O/p : Yes

I/p : G->E->E->K
O/p : No

Time: O(n)
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
    Node *curr = head, *prev = NULL, *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool checkPalindrome(Node *head)
{
    Node *fast = head, *slow = head, *curr = head;
    // find the middle
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow becomes the middle node
    Node *revNode = reverse(slow->next); // reverse the linked list after middle node
    while (revNode != NULL)
    {
        if (curr->data != revNode->data) // compare both half reversed node and from first 
            return false;
        curr = curr->next;
        revNode = revNode->next;
    }
    return true;
}

int main()
{
    Node *head = new Node('R');
    head->next = new Node('A');
    head->next->next = new Node('D');
    head->next->next->next = new Node('A');
    head->next->next->next->next = new Node('R');
    cout << checkPalindrome(head);
    return 0;
}