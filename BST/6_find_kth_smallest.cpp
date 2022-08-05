/*
Find the kth smallest element in bst
*/

/* Naive solution , Time: O(h+k)
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

static int counti = 0;

void findKthSmallest(Node *root, int k)
{
    if (root != NULL)
    {
        findKthSmallest(root->left, k);
        counti++;
        if (counti == k)
        {
            cout << root->key;
            return;
        }
        findKthSmallest(root->right, k);
    }
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int k = 3;
    findKthSmallest(root, k);
    return 0;
}
*/


// Efficient Solution , Time : O(h) but needs modification of node structure
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right;
  int lCount;
  Node(int k){
      key=k;
      left=right=NULL;
      lCount=0;
  }
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->key) {
        root->left = insert(root->left, x);
        root->lCount++;
    }
 
    else if (x > root->key)
        root->right = insert(root->right, x);
    return root;
}

Node* kthSmallest(Node* root, int k)
{
    if (root == NULL)
        return NULL;
 
    int count = root->lCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthSmallest(root->left, k);
 
    return kthSmallest(root->right, k - count);
}

int main() {
	
	Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->key;
    return 0;
	
}