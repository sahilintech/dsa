/*
Given a tree in which two nodes are misplaced. Swap these two nodes to make it bst

Time: O(n)
Space: O(h)
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
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
Node *previ = NULL, *first = NULL, *second = NULL;
int newi; // making previ var to compare if traversal is in ascending order or not
void fixBST(Node *root)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (previ != NULL && root->key < previ->key) // if root->key is less than previous key node val is misplaced
    {
        if (first == NULL)
            first = previ; // 1st misplaced key stored in first and second one in second
        second = root; // two nodes are misplaced only when first misplaced val is larger than second
    }
    previ = root;
    fixBST(root->right);
}

void printBST(Node *root)
{
    if (root != NULL)
    {
        printBST(root->left);
        cout << root->key << " ";
        printBST(root->right);
    }
}

int main()
{
    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->left->left = new Node(4);
    root->right->left = new Node(8);
    root->right->right = new Node(80);
    cout << "Before fixing" << endl;
    printBST(root);
    fixBST(root);
    swap(first->key, second->key);
    cout<<endl;
    cout << "After fixing" << endl;
    printBST(root);
    return 0;
}