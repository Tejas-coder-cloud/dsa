/*
N = Number of nodes 
H = Height of tree
Time complexity:O(N)
Space complexity:O(H) for normal trees and O(N) for skewed trees
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*left,*right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
bool isBST(Node* & root,int minVal,int maxVal)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=minVal && root->data<=maxVal)
    {
        bool left=isBST(root->left,minVal,root->data);
        bool right=isBST(root->right,root->data,maxVal);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(Node* & root)
{
    return isBST(root,INT_MIN,INT_MAX);
}
int main()
{
    Node* root=new Node(70);
    root->left=new Node(50);
    root->right=new Node(80);
    root->left->left=new Node(40);
    root->left->right=new Node(60);
    root->right->left=new Node(75);
    root->right->right=new Node(90);
    bool check=validateBST(root);
    if(check)
    {
        cout<<"Given BST is a valid BST ";
    }
    else
    {
        cout<<"Given BST is not  a valid BST ";
    }
    return 0;
}