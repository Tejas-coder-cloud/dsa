#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data )
    {
        this->data=data;
        this->next=NULL;
    }
};
Node *floydcycle(Node * &head)
{   if(head==NULL)
    {
        return NULL;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            cout<<"Present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node * startingNode(Node* &head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node*intersection=floydcycle(head);
    if(intersection==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node* removeloop(Node * &head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node*start=startingNode(head);
    if(start==NULL)
    {
        return head;
    }
    Node*temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return temp;
}
void print(Node* &head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node * head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    head->next->next=head;
    if(floydcycle(head))
    {
        cout<<"Linked list contains a loop"<<endl;
    }
    else
    {
        cout<<"Linked list doesn't contain a loop"<<endl;
    }
    cout<<"Starting at  "<<startingNode(head)->data<<endl;
    removeloop(head);
    print(head);
    return 0;
}
// Time complexity:O(n)
//Space complexity:O(1)