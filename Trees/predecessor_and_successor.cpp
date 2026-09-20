/*
Time complexity: O(N)
Space complexity: O(1)
For predecessor - Find maximum in the left subtree
For successor - Find minimum in the right subtree
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
pair<int,int> predecessorAndSuccessor(Node* &root,int key)
{
    // Find key
    Node* temp=root;
    int predecessor=-1,successor=-1;
    while(temp->data!=key)
    {
        if(temp->data>key)
        {
            successor=temp->data;
            temp=temp->left;
        }
        else 
        {
            predecessor=temp->data;
            temp=temp->right;
        }
    }
    // Find predecessor
    Node* leftTree=temp->left;
    while(leftTree!=NULL)
    {
        predecessor=leftTree->data;
        leftTree=leftTree->right;
    }
    // Find successor 
    Node* rightTree=temp->right;
    while(rightTree!=NULL)
    {
        successor=rightTree->data;
        rightTree=rightTree->left;
    }
    return {predecessor,successor};
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
    pair<int,int> ans=predecessorAndSuccessor(root,90);
    cout<<"The predecessor is: "<<ans.first<<" and the successor is: "<<ans.second<<endl;
    return 0;
}