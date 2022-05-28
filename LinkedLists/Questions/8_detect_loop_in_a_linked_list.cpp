/*
Given a singly linked list. Detect loop in it. i.e If last node is not pointing to NULL

I/p : 10->20->30-40-> ( let say 40 is again pointing to 10)
O/p : Yes

I/p : 10->20
O/p : NO


// Time: O(n), Space : O(1) , Modifies pointers of linked list. Destroys linked list but detects loop

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

bool detectLoop(Node *head)
{
    Node *dummy = new Node(0); // create a dummy node
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == dummy) // if curr->next points to dummy then loop detected
            return true;
        Node *temp = curr->next;
        curr->next = dummy; // point every node to dummy node
        curr = temp;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

*/

// More Efficient Solution, Does not modifies anything , Time : O(n), Space: O(n)
// Requires hashing

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

bool detectLoop(Node *head)
{
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end()) // if curr node is already present in set return true
            return true;
        else
            s.insert(curr); // else add it
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

