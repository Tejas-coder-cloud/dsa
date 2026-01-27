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
int getlength(Node* head)
{
    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
Node*removeKthNode(Node* head,int n)
{
    int N=getlength(head);
    int k=N-n;
    Node*dummy=new Node(0,head);
    Node* temp=dummy;
    for(int i=0;i<k;i++)
    {
        temp=temp->next;
    }
    Node* nodetodelete=temp->next;
    temp->next=temp->next->next;
    delete nodetodelete;
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
    vector<int> v={5,4,3,2,1};
    int x=1;
    Node* head=createlist(v);
    display(head);
    Node*result=removeKthNode(head,x);
    display(result);
    return 0;
}