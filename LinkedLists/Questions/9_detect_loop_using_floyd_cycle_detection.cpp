/*Given a singly linked list. Detect loop in it. i.e If last node is not pointing to NULL

I/p : 10->20->30-40-> ( let say 40 is again pointing to 10)
O/p : Yes

I/p : 10->20
O/p : NO

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

bool detectLoop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next; // move fast as twice of slow
        if (slow == fast) // if there will be loop they will meet at some point because fast is moving twice as slow
            return true;
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