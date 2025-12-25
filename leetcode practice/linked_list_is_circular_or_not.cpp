#include<bits./stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int data )
    {
        this->data=data;
        this->next=NULL;
    }
};
bool isCircular(Node* head)
{
    if(head==NULL)
    {
        return true;
    }
    Node*temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return false;
    }
    return true;
}
int main()
{
    Node * head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=head;

    if(isCircular(head))
    {
        cout<<"Linked list is circular";
    }
    else
    {
        cout<<"Linked list is not circular";
    }
    return 0;
}
/*
Other  approach 
#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
  int data;
  Node* next;
  Node(int data)
  {
    this->data=data;
    this->next=next;
   }

};
bool isCircular(Node* & head)
{
   if(head==NULL)
   {
    return true;
   }
    Node* slow=head;
    Node * fast=head->next;
    while(fast && fast>next)
    {
     if(slow==fast)
     {
     return true;
     slow=slow->next;
     fast=fast->next->next;
     }
    }
  return false;
}
  int main()
  {
  Node * head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=head;

    if(isCircular(head))
    {
        cout<<"Linked list is circular";
    }
    else
    {
        cout<<"Linked list is not circular";
    }
    return 0;
  }
*/
