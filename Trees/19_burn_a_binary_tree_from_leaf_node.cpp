/*
Given a binary tree and a leaf node. Burn the binary tree from the leaf and calculate the time taken to burn whole tree. Basically
find the distance of farthest node from the given leaf

*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
    int key;
    Node *right, *left;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

void burnBT(Node *root, int leaf, int &dist)
{

}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->right = new Node(5);
    root->left->left = new Node(30);
    root->left->left->right = new Node(50);
    root->left->left->left = new Node(40);
    root->left->left->left->left = new Node(60);
    root->left->left->left->left->left = new Node(70);
    int leaf = 50;
    int dist = -1;
    burnBT(root, leaf, dist);
    return 0;
}