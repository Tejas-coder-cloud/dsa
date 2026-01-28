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
int count_occurence(Node* head, int key)
{
    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        if(temp->data==key)
        {
            cnt++;
        }
        temp=temp->next;
    }
    return cnt;
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
    vector<int> v={5,4,2,2,2};
    int x=2;
    Node* head=createlist(v);
    display(head);
    int occurence=count_occurence(head,x);
    cout<<"The occurenece of the node with data "<<x<<" is "<<occurence<<endl;
    return 0;
}