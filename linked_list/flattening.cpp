/*
Flatten a linked list 
N = Average number of nodes in a single vertical column
M = Total number of horizontal columns
Time complexity: O(N*M^2)
Space complexity: O(N*M)
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next,*bottom;
    Node(int val):data(val),next(NULL),bottom(NULL) {}
};
Node* merge(Node* a, Node* b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node* result;
    if(a->data<=b->data)
    {
        result=a;
        result->bottom=merge(a->bottom,b);
    }
    else
    {
        result=b;
        result->bottom=merge(a,b->bottom);
    }
    result->next=NULL;
    return result;
}
Node* flatten(Node* root)
{
    if(root==NULL || root->next==NULL)
    {
        return root;
    }
    root->next=flatten(root->next);
    root=merge(root,root->next);
    return root;
}
void flattenlist(Node* head)
{
    cout<<"Flatten List: ";
    while(head)
    {
        cout<<head->data<<"->";
        head=head->bottom;
    }
    cout<<"NULL";
}
int main()
{
    Node* head=new Node(1);
    head->bottom=new Node(2);
    head->bottom->bottom=new Node(4);
    head->next=new Node(3);
    head->next->bottom=new Node(5);
    head->next->bottom->bottom=new Node(6);
    head=flatten(head);
    flattenlist(head);
    return 0;
}