/* Given a linked list and value x . Return position of value if it is present in linked list else
return -1
I/p : 10->20->30->40, data = 30
O/p : 3

I/p : 10->20->30 , data = 40
O/p : -1


******************** ITERATIVE SOLUTION **********************
Time : O(n), Space O(1)

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

int search(Node *head, int givenData)
{
    Node *curr = head;
    int pos = 1;
    while (curr != NULL)
    {
        if (curr->data == givenData)
            return pos;
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    int givenData = 10;
    cout << search(head, givenData);
    return 0;
}

*/

// Recursive Solution  Time : O(n), Space : O(n);
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

int recursiveSearch(Node *head, int givenData, int pos = 1)
{
    if (head == NULL)
        return -1;
    if (head->data == givenData)
        return pos;
    recursiveSearch(head->next, givenData, pos+1);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    int givenData = 50;
    cout << recursiveSearch(head, givenData);
    return 0;
}