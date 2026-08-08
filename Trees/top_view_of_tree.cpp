#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
Node* buildTree(vector<int> & preorder,int & index)
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
void topview(Node* & root)
{
    queue<pair<Node* ,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty())
    {
        Node* curr=q.front().first;
        int currHD=q.front().second;
        q.pop();
        if(m.find(currHD)==m.end())
        {
            m[currHD]=curr->data;
        }
        if(curr->left!=NULL)
        {
            q.push({curr->left,currHD-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,currHD+1});
        }
    }
    cout<<"Top view of the tree is given as follows: ";
    for(auto it: m)
    {
        cout<<it.second<<" ";
    }
}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* root=buildTree(preorder,index);
    topview(root);
    return 0;
}