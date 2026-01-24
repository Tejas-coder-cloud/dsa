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
Node*addLL(Node* l1,Node* l2)
{
    Node* dummy=new Node(0);
    Node* curr=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry!=0)
    {
        int x=(l1!=NULL)?l1->data:0;
        int y=(l2!=NULL)?l2->data:0;
        int sum=x+y+carry;
        carry=sum/10;
        curr->next =new Node(sum %10);
        curr=curr->next;
        if (l1!=NULL) l1=l1->next;
        if (l2!=NULL) l2=l2->next;
    }
    Node *result=dummy->next;
    delete dummy;
    return result;
}
Node*createlist(vector<int> &v)
{
    if(v.empty())
    {
        return NULL;
    }
    Node* head=new Node(v[0]);
    Node*temp=head;
    for(int i=1;i<v.size();i++)
    {
        temp->next=new Node(v[i]);
        temp=temp->next;
    }
    return head;
}
void display(Node * head)
{
    Node* temp=head;
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
    vector<int> v1={1,2,4};
    vector<int> v2={4,5,6};
    Node* head1=createlist(v1);
    Node* head2=createlist(v2);
    display(head1);
    display(head2);
    Node* add=addLL(head1,head2);
    display(add);
    return 0;
}
/*
The code calculates the addition of the linked list when both are reversed 
Example l1= 1->2->3
l2=4->5->6
result=9->7->5
*/