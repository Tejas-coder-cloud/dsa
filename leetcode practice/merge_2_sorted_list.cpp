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
Node* merge2list(Node* list1,Node*list2)
{
        if(list1==NULL && list2==NULL)
        {
            return NULL;
        }
        Node * dummy=new Node(0);
        Node* head=dummy;
        while(list1 && list2)
        {
            if(list1->data<=list2->data)
            {
                head->next=list1;
                list1=list1->next;
            }
            else
            {
                head->next=list2;
                list2=list2->next;
            }
            head=head->next;
        }
        if(list1)
        {
            head->next=list1;
        }
        if(list2)
        {
            head->next=list2;
        }
        return dummy->next;
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
    vector<int> v1={1,2,4};
    vector<int> v2={1,2,3};
    Node* head1=createlist(v1);
    display(head1);
    Node* head2=createlist(v2);
    display(head2);
    Node*result=merge2list(head1,head2);
    display(result);
    return 0;
}