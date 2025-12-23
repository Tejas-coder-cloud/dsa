#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data )
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node()
    {
        cout<<"Node with "<<data<<" deleted";
        cout<<endl;
    }
};
void insertatposition(Node* &tail,int data,int position)
{
    if(tail==NULL)
    {
        Node* newNode=new Node(data);
        newNode->next=newNode;
        newNode->prev=newNode;
        tail=newNode;
        return;
    }
    if(position==1)
    {
        Node* head = tail->next;
        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        return;
    }
    Node * newNode=new Node(data);
    Node*temp=tail->next;
    int cnt=1;
    while(cnt<position-1 )
    {
        temp=temp->next;
        cnt++;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
    if(temp==tail)
    {
        tail=newNode;
    }
}
void deleteposition(Node * & tail, int position)
{
    if(tail==NULL)
    {
        cout<<"Invalid position ";
        return;
    }
    Node *head=tail->next;
    if(head==tail && position==1)
    {
        head->prev=NULL;
        head->next=NULL;
        delete head;
        return;
    }
    int cnt=1;
    Node* curr=head;
    while(cnt<position)
    {
        cnt++;
        curr=curr->next;
    }
    Node *prevNode=curr->prev;
    Node *currNode=curr->next;
    prevNode->next=currNode;
    currNode->prev=prevNode;
    if(curr==tail)
    {
        tail=prevNode;
    }
    curr->prev=NULL;
    curr->next=NULL;
    delete curr;
}
void display(Node* &tail)
{
    Node * temp=tail->next;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
    cout<<endl;
}
int main()
{
    Node* tail=NULL;
    insertatposition(tail,10,1);
    insertatposition(tail,20,2);
    insertatposition(tail,30,3);
    insertatposition(tail,40,4);
    insertatposition(tail,50,5);
    display(tail);
    deleteposition(tail,3);
    display(tail);
    return 0;
}