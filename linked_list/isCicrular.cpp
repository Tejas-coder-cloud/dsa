/* 
Check whether the linked list is circular or not 
Time complexity: O(n),Space complexity: O(1)
*/
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
bool isCircular(Node* & head)
{
    Node* slow=head;
    Node* fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
void display(Node * & head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    Node* temp=head;
    cout<<"Linked list is as follows: ";
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> v={1,2,3,4};
    Node* head=createlist(v);
    display(head);
    bool ans=isCircular(head);
    if(ans)
    {
        cout<<"Linked list is circular"<<endl;
    }
    else
    {
        cout<<"Linked list is not circular"<<endl;
    }
    return 0;
}