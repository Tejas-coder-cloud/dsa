/*
Time complexity:O(n)
Space complexity:O(H)
H=height of the tree 
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
static int index=-1;
Node* buildTree(vector<int> &preorder)
{
    index++;
    if(preorder[index]==-1)
    {
        return NULL;
    }
    Node* root=new Node(preorder[index]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);
    return root;
}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(preorder);
    cout<<root->data<<endl;
    return 0;
}