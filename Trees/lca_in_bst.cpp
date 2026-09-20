/*
LCA = Lowest common ancestor 
Time complexity:O(N)
Space complexity:O(1)
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
        this->left=NULL;
        this->right=NULL;
    }
};
Node* LCA(Node* & root,Node* a,Node* b)
{
    // Base case
    // if(root==NULL)
    // {
    //     return NULL;
    // } 
    // if(root->data<a->data && root->data<b->data)
    // {
    //     return LCA(root->right,a,b);
    // }
    // if(root->data>a->data && root->data>b->data)
    // {
    //     return LCA(root->leftt,a,b);
    // }
    // return root;
    if(root==NULL)
    {
        return root;
    }
    while(root!=NULL)
    {
        if(root->data<a->data && root->data<b->data)
        {
            root = root->right;
        }
        else if(root->data>a->data && root->data>b->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
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
    Node* ans=LCA(root,root->left,root->right);
    cout<<"The LCA is: "<<ans->data<<endl;
    return 0;
}