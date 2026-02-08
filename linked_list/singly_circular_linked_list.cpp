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
        this->next=this;
    }
    ~Node()
    {
        cout << "Node with data " << data << " destroyed\n";
        cout<<"Destructor called"<<"\n";
    }
};
void insertatposition( Node* & tail, int data, int position )
{
    if(tail==NULL)
    {
        Node * newNode=new Node(data);
        tail=newNode;
        newNode->next=newNode;
        return;
    }
    if(position==1)
    {
        Node*newNode=new Node(data);
        newNode->next=tail->next;
        tail->next=newNode;
        return;
    }
    int cnt=1;
    Node*temp=tail->next;
    while(cnt<position-1 && temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL)
    {
        cout<<"Invalid index";
        return;
    }
     Node * newNode=new Node(data);
     newNode->next=temp->next;
     temp->next=newNode;
     if(temp==tail)
     {
        tail=newNode;
     }
}
void deletenode(Node * &tail, int position)
{
    if(tail==NULL)
    {
        cout<<"Linked list is empty"<<" ";
        return;
    }
    if(position==1)
    {
        Node*temp=tail->next;
        if(temp==tail)
        {
            tail=NULL;
        }
        else
        {
            tail->next=temp->next;
        }
        temp->next=NULL;
        delete temp;
        return;
    }
    int cnt=1;
    Node* prev=tail->next;
    while(cnt<position-1 )
    {
        prev=prev->next;
        cnt++;
        if(prev==tail->next)
        {
            cout<<"Index out of bounds"<<" ";
            return;
        }
    }
    Node*curr=prev->next;
    if(position>1 && prev==tail)
    {
        cout<<"Invalid position";
        return;
    }
    prev->next=curr->next;
    if(curr==tail)
    {
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
}
void display(Node* & tail)
{
   if(tail==NULL)
   {
     cout<<"List is empty"<<" ";
     return;
   } 
   Node *temp=tail->next;
   cout<<"Circular singly linked list is as follows:";
   do
   {
    cout<<temp->data<<" ";
    temp=temp->next;

   }while(temp!=tail->next);
   cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* tail=NULL;
    insertatposition(tail,10,1);
    insertatposition(tail,20,2);
    insertatposition(tail,30,3);
    insertatposition(tail,40,4);
    insertatposition(tail,50,5);
    display(tail);
    deletenode(tail,1);
    display(tail);
    return 0;
}