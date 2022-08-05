/*
Delete given node in binary tree

Time : O(h)
Space : O(h)
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

Node *getSuccessor(Node *root)
{
    Node *curr = root;
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteInBST(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
        root->left = deleteInBST(root->left, x);  // for finding the node go to left checking condition
    else if (root->key < x)
        root->right = deleteInBST(root->right, x);
    else
    {
        if (root->left == NULL) // handle both cases if root has right child or both child are null
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) // handle if left child is null
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else // if root has both childs
        {
            Node *succ = getSuccessor(root); // find next larget element thant root
            root->key = succ->key; // make current root same as found successor
            root->right = deleteInBST(root->right, succ->key); // delete one same element
        }
    }
}

void printBST(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        printBST(root->left);
        printBST(root->right);
    }
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int x = 50;
    Node *newRoot = deleteInBST(root, x);
    printBST(newRoot);
    return 0;
}