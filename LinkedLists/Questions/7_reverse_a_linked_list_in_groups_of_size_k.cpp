/*
Given a linked list. Reverse it in groups of size k

I/p : 10->20->30->40->50->60 , k = 3
O/p : 30->20->10->60->50->40

I/p : 10->20->30->40->50, k = 3
O/p : 30->20->10->50->40


// ***************** Recursive Solution ******************

TIME : O(n) , Space : O(n/k)
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

Node *reverseInGroups(Node *head, int k)
{
    Node *curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        Node *restHead = reverseInGroups(next, k);
        head->next = restHead;
    }
    return prev;
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
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    int k = 3;
    head = reverseInGroups(head, k);
    printList(head);
    return 0;
}

*/

// Iterative Solution, Time : O(n)
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

Node *reverseInGroups(Node *head, int k)
{
    Node *curr = head, *next = NULL, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
            prevFirst->next = prev;
        prevFirst = first;
    }
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
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    int k = 3;
    head = reverseInGroups(head, k);
    printList(head);
    return 0;
}