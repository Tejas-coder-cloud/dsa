/*
Time complexity:O(n)
Space complexity:O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int countNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
}
bool isCBT(Node* root,int index,int count)
{
    if(root==NULL)
    {
        return true;
    }
    if(index>=count)
    {
        return false;
    }
    else
    {
        bool left=isCBT(root->left,2*index+1,count);
        bool right=isCBT(root->right,2*index+2,count);
        return left&& right;
    }
}
bool isMaxHeap(Node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    if(root->right==NULL)
    {
        return (root->data>root->left->data) && isMaxHeap(root->left);
    }
    else
    {
        bool left=isMaxHeap(root->left);
        bool right=isMaxHeap(root->right);
        return (left && right && (root->data> root->left->data && root->data > root->right->data));
    }
}
bool isHeap(Node* root)
{
    int index=0;
    int totalCount=countNodes(root);
    if(isCBT(root,index,totalCount) && isMaxHeap(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node* root= new Node(50);
    root->left= new Node(20);
    root->right= new Node(30);
    root->left->left= new Node(70);
    root->left->right= new Node(5);
    if(isHeap(root))
    {
        cout<<"The Binary tree is a Heap "<<endl;
    }
    else
    {
        cout<<"The Binary tree is not a Heap "<<endl;
    }
    return 0;
}