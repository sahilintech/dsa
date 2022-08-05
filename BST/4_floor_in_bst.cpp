/*
Find the largest closer value to the given x which should also be smaller than it

Time : O(h)
Space : O(1)
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

Node *findFloorInBST(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x) // if found return immediately
            return root;
        else if (root->key > x)
            root = root->left;
        else
        {
            res = root; // always store smaller value than x for result
            root = root->right;
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int x = 85;
    Node *floor = findFloorInBST(root, x);
    cout << floor->key;
    return 0;
}