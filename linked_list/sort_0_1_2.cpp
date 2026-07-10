/* 
sort 0s,1s,2s in a linked list 
Time complexity: O(2n)
Space complexity: O(1)
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
    if(v.empty())
    {
        return NULL;
    }
    Node* temp=new Node(v[0]);
    Node* curr=temp;
    for (int i = 1; i < v.size(); i++)
    {
        curr->next=new Node(v[i]);
        curr=curr->next;
    }
    return temp;
}
Node* sortlist(Node* & head)
{
    int zeroCount=0,oneCount=0,twoCount=0;
    Node* temp=head;
    while(temp)
    {
        if(temp->data==0)
        {
            zeroCount++;
        }
        if(temp->data==1)
        {
            oneCount++;
        }
        if(temp->data==2)
        {
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp)
    {
        if(zeroCount!=0)
        {
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0)
        {
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
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
    vector<int> v={2,2,1,1,0,1,0};
    Node* head=createlist(v);
    display(head);
    Node*result=sortlist(head);
    display(result);
    return 0;
}