/*
Insertion
n = Number of nodes
H= Height of tree
Time complexity:O(logn)
Space complexity:O(n)
Searching
Time complexity:O(n) for skewed trees and O(H) for rest
Space complexity:O(n) for recursive solution and O(1) for iterative
Inorder of BST is always sorted 
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void findMinAndMax(Node*&root)
{
    Node*temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    cout<<"The minimum value is: "<<temp->data;
    temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    cout<<endl;
    cout<<"The maximum value is: "<<temp->data;
}
Node *insertIntoBST(Node *&root, int data)
{
    // Base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Insert into right part
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void inorder(Node* &root) {
    //base case
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}
bool searchInBST(Node *&root, int x)
{
    // Base case
    // if(root==NULL)
    // {
        //     return false;
        // }
        // if(root->data==x)
        // {
            //     return true;
            // }
            // if(root->data>x)
    // {
    //     return searchInBST(root->left,x);
    // }
    // else
    // {
    //     return searchInBST(root->right,x);
    // }
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (temp->data > x )
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return false;
}
Node* minVal(Node* &root)
{
    Node*temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* deleteFromBST(Node* & root,int x)
{
    // Base case
    if(root==NULL)
    {
        return NULL;
    } 
    if(root->data==x)
    {
        // 0 child --> leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // Left child
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child 
        if(root->right!=NULL && root->left==NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>x)
    {
        root->left=deleteFromBST(root->left,x);
        return root;
    }
    else 
    {
        root->right=deleteFromBST(root->right,x);
        return root;        
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create Binary Search Tree: (Enter -1 to stop ) ";
    takeInput(root);
    levelOrderTraversal(root);
    cout << searchInBST(root, 25);
    cout<<endl;
    findMinAndMax(root);
    root=deleteFromBST(root,50);
    cout<<endl;
    levelOrderTraversal(root);
    return 0;
}