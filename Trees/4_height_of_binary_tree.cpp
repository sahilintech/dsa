/*
Given a binary tree return its height

I/p : 10->20->30->40
O/p : 4

Time : O(n)
Space : O(h)
*/

#include<iostream>
#include<algorithm>
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

int heightOfTree(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(heightOfTree(root->right), heightOfTree(root->left))+1;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(70);
    cout<<heightOfTree(root);
    return 0;
}