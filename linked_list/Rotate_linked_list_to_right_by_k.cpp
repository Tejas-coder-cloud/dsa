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
 Node* rotateRight(Node* head, int k) 
 {
    if (!head || k == 0) return head;
    Node* curr = head;
    int len = 1;
    while (curr->next && ++len) 
    {
        curr = curr->next;
    }
    curr->next = head; 
    k = len - (k % len);
    while (k--) 
    {
    curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;        
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
    int k=1;
    Node* result=rotateRight(head,k);
    display(result);
    return 0;
}
