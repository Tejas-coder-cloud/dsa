/*    
Merge sort in a linked list 
Time complexity: O(nlogn),Space complexity: O(logn)
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node():data(0),next(NULL) {}
    Node(int val):data(val),next(NULL) {}
    Node(int val,Node* next):data(val),next(next) {}
};
Node* getMid(Node * & head)
{
    Node* slow=head;
    Node* fast=head->next;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node * createlist(vector<int> &v)
{
    Node* temp=new Node(v[0]);
    Node* curr=temp;
    for (int i = 1; i < v.size(); i++)
    {
        curr->next=new Node(v[i]);
        curr=curr->next;
    }
    return temp;
}
Node* merge(Node* left,Node* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    Node* ans=new Node(-1);
    Node* temp=ans;
    while(left && right)
    {
        if(left->data<right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return ans->next;
}
Node* mergesort(Node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node*left=head;
    Node* middle=getMid(head);
    Node* right=middle->next;
    middle->next=NULL;
    left=mergesort(left);
    right=mergesort(right);
    Node* result=merge(left,right);
    return result;
}
void display(Node * & head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    Node* temp=head;
    cout<<"Linked list is as follows: ";
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> v={4,3,2,1};
    Node* head=createlist(v);
    display(head);
    Node*result=mergesort(head);
    display(result);
    return 0;
}