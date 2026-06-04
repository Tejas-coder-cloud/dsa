//  Add  1 to linked list 
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
    Node*prev=NULL;
    Node*curr=head;
    while(curr)
    {
        Node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
Node*add1(Node*&head)
{
    head=reverse(head);
    Node*curr=head;
    int carry=1;
    while(curr && carry)
    {
        int sum=curr->data+carry;
        curr->data=sum%10;
        carry=sum/10;
        if(carry && curr->next==nullptr)
        {
            curr->next=new Node(0);
        }
        curr=curr->next;
    }
    return reverse(head);
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
    Node* newHead=add1(head);
    display(newHead);
    return 0;
}