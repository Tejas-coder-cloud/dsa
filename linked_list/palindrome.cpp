// Check whether the linked list is palindromic or not 
// Time complexity: O(n),Space complexity: O(1)
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
Node * reverse(Node * & head)
{
    Node* prev=NULL;
    Node* curr=head;
    while(curr)
    {
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
Node* getMid(Node * & head)
{
    Node* slow=head;
    Node* fast=head->next;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
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
bool isPalindrome(Node* & head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    Node* middle=getMid(head);
    Node* temp=middle->next;
    Node* head2=reverse(temp);
    Node* head1=head;
    while(head2)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
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
    bool ans=isPalindrome(head);
    if(ans)
    {
        cout<<"Linked list is palindromic"<<endl;
    }
    else
    {
        cout<<"Linked list is not palindromic"<<endl;
    }
    return 0;
}