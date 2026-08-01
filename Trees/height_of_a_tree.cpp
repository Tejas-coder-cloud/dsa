/*
Height of a tree
Time complexity:O(N)
Space complexity:O(N)
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
int height(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftHt= height(root->left);
    int rightHt = height(root->right);
    return max(leftHt,rightHt)+1;
}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(preorder);
    int ans=height(root);
    cout<<"The height of the tree is: "<<ans<<endl;
    return 0;
}