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
int solve(Node* & root,int &i, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    // Left part 
    int left=solve(root->left,i,k);
    if(left!=-1)
    {
        return left;
    }
    // Root node part
    i++;
    if(i==k)
    {
        return root->data;
    }
    // Right part
    return solve(root->right,i,k);
}
int kthSmallest(Node*&root,int i , int k )
{
    int ans=solve(root,i,k);
    return ans;
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
    int i=0,k=5;
    int ans=kthSmallest(root,i,k);
    if(ans==-1)
    {
        cout<<"The "<<k<<" th"<<" smallest element doesn't exist"<<endl;
    }
    else
    {
        cout<<"The "<<k<<" th "<<" smallest element is: "<<ans<<endl;
    }
    return 0;
}