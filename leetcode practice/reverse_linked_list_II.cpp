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
Node* reverse(Node * head, int left,int right)
{
    if(!head || left==right)
    {
        return head;
    }
    Node* dummy=new Node(0);
    dummy->next=head;
    Node*prev=dummy;
    for(int i=0;i<left-1;++i)
    {
        prev=prev->next;
    }
    Node* curr=prev->next;
    for(int i=0;i<right-left;i++)
    {
        Node* temp=curr->next;
        curr->next=temp->next;
        temp->next=prev->next;
        prev->next=temp;
    }
    Node* result=dummy->next;
    delete dummy;
    return result;
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
    vector<int> v={1,2,3,4,5,6};
    Node* head=createlist(v);
    display(head);
    int left=1,right=3;
    Node* result=reverse(head,left,right);
    display(result);
    return 0;
}