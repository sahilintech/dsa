#include <iostream>
#include <algorithm>
#include "0_header.h"
using namespace std;

/* Time: O(n^2)

int diameterOfBT(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return max(lh + rh + 1, max(diameterOfBT(root->left), diameterOfBT(root->right)));
}

*/

int res = 0;
int diameterOfBT(Node *root)  // modifying the height function and doing it in O(n)
{
    if (root == NULL)
        return 0;
    int lh = diameterOfBT(root->left);
    int rh = diameterOfBT(root->right);
    res = max(res, 1+lh+rh);
    return (1+max(lh, rh));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(18);
    root->left->left = new Node(30);
    root->left->left->right = new Node(50);
    root->left->left->left = new Node(40);
    root->left->left->left->left = new Node(60);
    root->right = new Node(60);
    diameterOfBT(root);
    cout<<res;
    return 0;
}
