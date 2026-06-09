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
Node* partition(Node* head,int x)
{
   Node* small=new Node(0);
        Node* large=new Node(0);
        Node* equal=new Node(0);
        Node* smallnode=small;
        Node* largenode=large;
        Node* equalnode=equal;
        while(head)
        {
            if(head->data<x)
            {
                smallnode->next=head;
                smallnode=smallnode->next;
            }
            else if(head->data>x)
            {
                largenode->next=head;
                largenode=largenode->next;
            }
            else
            {
                equalnode->next=head;
                equalnode=equalnode->next;
            }
            head=head->next;
        }
        largenode->next=NULL;
        equalnode->next=large->next;
        smallnode->next=equal->next;
        return small->next;
}
Node * createlist(vector<int> &v)
{
    if(v.empty())
    {
        return NULL;
    }
    Node* head=new Node(v[0]);
    Node* temp=head;
    for(int i=1;i<v.size();i++)
    {
        temp->next=new Node(v[i]);
        temp=temp->next;
    }
    return head;
}
void display(Node* head)
{
    Node*temp=head;
    cout<<"Linked list is as follows: ";
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={5,4,3,2,1};
    int x=3;
    Node* head=createlist(v);
    display(head);
    Node*result=partition(head,x);
    display(result);
    return 0;
}