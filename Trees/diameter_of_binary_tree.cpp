/*
Diameter of a binary tree
Time complexity:O(N^2)
Space complexity:O(N)
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* buildTree(vector<int> & preorder , int &index)
{
    index++;
    if(preorder[index]==-1)
    {
        return NULL;
    }
    Node* root=new Node(preorder[index]);
    root->left=buildTree(preorder,index);
    root->right=buildTree(preorder,index);
    return root;
}
int height(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return max(leftHeight,rightHeight)+1;
}
int diameter(Node* & root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftDiam=diameter(root->left);
    int rightDiam=diameter(root->right);
    int currDiam=height(root->left)+height(root->right);
    return max(currDiam,max(leftDiam,rightDiam));
}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1}; int index=-1;
    Node* root=buildTree(preorder,index);
    int ans=diameter(root);
    cout<<"The diameter of the binary tree is: "<<ans<<endl;
    return 0;
}