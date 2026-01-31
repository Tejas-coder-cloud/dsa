#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node():data(0),next(NULL),prev(NULL) {}
    Node(int val):data(val),next(NULL),prev(NULL) {}
    Node(int val,Node* next,Node*prev):data(val),next(next),prev(prev) {}
};
Node* reversal(Node* head)
{
    if(head==NULL|| head->next==NULL)
    {
        return head;
    }
    swap(head->prev,head->next);
    if(head->prev==NULL)
    {
        return head;
    }
    return reversal(head->prev);
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
       Node* newNode=new Node(v[i]);
       temp->next=newNode;
       newNode->prev=temp;
       temp=newNode;
    }
    return head;
}
void display(Node* head)
{
    Node*temp=head;
    cout<<"Linked list is as follows: "<<"NULL<-";
    while(temp)
    {
        cout<<temp->data<<"<->";
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
    Node* head=createlist(v);
    display(head);
    Node*result=reversal(head);
    display(result);
    return 0;
}