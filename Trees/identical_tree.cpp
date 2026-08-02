/*
Check whether trees are same or not
Time complexity: O(N)
Space complexity: O(N)
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
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> preorder1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index1 = -1;
    Node *p = buildTree(preorder, index1);
    int index2 = -1;
    Node *q = buildTree(preorder1, index2);
    bool ans = isSameTree(p, q);
    if (ans)
    {
        cout << "The trees are identical\n";
    }
    else
    {
        cout << "The trees are not identical\n";
    }
    return 0;
}