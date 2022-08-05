/*
Given a binary tree. Print vertical sum of that bst

Time: O(nloghd + hd) where log hd is for traversal of map and hd is total horizontal distances possible i.e size of map
Space: O(h + hd)
*/

#include <iostream>
#include <map>
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

void verticalSumOfBST(Node *root, int vari, map<int, int> &m)
{
    if (root == NULL)
        return;
    verticalSumOfBST(root->left, vari - 1, m);
    m[vari] += root->key;
    verticalSumOfBST(root->right, vari + 1, m);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right = new Node(50);
    map<int, int> m;
    verticalSumOfBST(root, 0, m);
    for (auto i : m)
        cout << i.second << " ";
    return 0;
}