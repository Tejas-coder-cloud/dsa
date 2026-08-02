/*
Check whether a tree is a subtree of another tree
Time Complexity: O(N × M)
N = Number of nodes in the main tree
M = Number of nodes in the subtree
Space Complexity: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(vector<int> &preorder, int &index)
{
    index++;
    if (preorder[index] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);
    return isLeftSame && isRightSame && (p->data == q->data);
}
bool isSubTree(Node *root, Node *subRoot)
{
    if (subRoot == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }
    if (root->data == subRoot->data && isSameTree(root, subRoot))
    {
        return true;
    }
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> preorder1 = {4, 4, -1, -1, 5, -1, -1};
    int index1 = -1;
    Node *p = buildTree(preorder, index1);
    int index2 = -1;
    Node *q = buildTree(preorder1, index2);
    bool ans = isSubTree(p, q);
    if (ans)
    {
        cout << "The tree q is a subtree of p\n";
    }
    else
    {
        cout << "The tree q is not a subtree of p\n";
    }
    return 0;
}