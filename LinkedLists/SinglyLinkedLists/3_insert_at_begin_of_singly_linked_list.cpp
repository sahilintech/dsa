/*
Given a singly linked list and value x,  insert x at begining of linked list

I/p : 10->20->30, x=5

O/p : 5->10->20->30

Time : O(1) for insertBegin function
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x); 
    temp->next = head; // address of head node is stored in temp since linking head as next node
    return temp; // new head is returned
}

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    printList(head);
    return 0;
}