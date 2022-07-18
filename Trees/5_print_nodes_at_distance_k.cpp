/*
Given a binary search tree. Print the nodes which are at a distance of k from the main root
i.e print whole k+1th level of tree
I/p : 10->20->30, k=2
O/p : 30

Time : O(n)
Space : O(h )
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

void printNodesAtDistanceK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->key << " ";
    else
    {
        printNodesAtDistanceK(root->left, k-1);
        printNodesAtDistanceK(root->right, k-1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(70);
    int k = 2;
    printNodesAtDistanceK(root, k);
    return 0;
}