/*

Given a binary tree convert it into doubly linked list in inplace. with using given links of binary tree


Time : O(n)
Space: O(h)
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
Node *btToDll(Node *root)
{
    static Node *prev = NULL;
    if (root == NULL)
        return root;
    Node *head = btToDll(root->left);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    btToDll(root->right);
    return head;
}

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->key<<" ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->left->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    Node *head = btToDll(root);
    printList(head);
    return 0;
}