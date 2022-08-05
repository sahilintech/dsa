/*
    Given a binary tree. Find the given val in it

    Time : O(h)
    Space : O(h) or O(1) if iterative
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


/* Recursive
bool searchInBST(Node *root, int x)
{
    if(root == NULL)
        return false;
    if(x < root->key)
        return(root->key == x || searchInBST(root->left, x));
    else
        return(root->key == x || searchInBST(root->right, x));
}
*/

// iterative
bool searchInBST(Node *root, int x)
{
    while(root != NULL)
    {
        if(root->key == x)
            return true;
        else if(root->key > x)
            root = root->left;
        else  
            root = root->right;
    }
    return false;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->left = new Node(80);
    int x = 2;
    cout<<searchInBST(root, x);
    return 0;
}