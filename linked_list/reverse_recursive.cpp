#include <bits/stdc++.h>
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
Node*reverse(Node*&head)
{ 
    if(head==NULL || head->next==NULL)
    {
        return head;
    } 
    Node* newHead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
void display(Node*&head)
{
    Node*temp=head;
    cout<<"Linked list is as follows ";
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;  
}
int main() 
{
    vector<int> v={1,2,3};
    Node* head=createlist(v);
    display(head);
    Node* newHead=reverse(head);
    display(newHead);
    return 0;
}