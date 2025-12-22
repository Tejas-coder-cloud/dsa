#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}
	~Node()
	{
		int value=this->data;
		if(this->next!=NULL)
		{
			delete next;
			next=NULL;
		}
	}
};
void insertathead(Node* &head, Node *&tail, int data)
{
	if(head==NULL)
	{
		Node* temp=new Node(data);
		head=temp;
		tail=temp;
	}
	else
	{
		Node*temp=new Node(data);
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void insertattail(Node* &head, Node *&tail, int data)
{
	if(tail==NULL)
	{
		Node* temp=new Node(data);
		head=temp;
		tail=temp;
	}
	else
	{
		Node*temp=new Node(data);
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void insertatposition(Node* &head, Node *&tail, int data,int position)
{
	if(position==1)
	{
		insertathead(head,tail,data);
		return;
	}
	Node* temp=head;
	int cnt=1;
	while(cnt<position-1 && temp!=NULL)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL)
	{
        insertattail(head,tail,data);
        return;
	}
	Node* nodetoinsert=new Node(data);
	nodetoinsert->next=temp->next;
	temp->next->prev=nodetoinsert;
	temp->next=nodetoinsert;
	nodetoinsert->prev=temp;
}
void deletenode(Node * & head, int position)
{
    if(position==1)
    {
    Node * temp=head;
    if(temp->next!=NULL)
    {
        temp->next->prev=NULL;
        head=temp->next;
    }
    else
    {
        head=NULL;
    }
    temp->next=NULL;
    delete temp;
    }
    else
    {
        Node*curr=head;
        Node* prevNode=NULL;
        int cnt=1;
        while(cnt<position && curr!=NULL)
        {
            prevNode=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr!=NULL)
        {
            if(curr->next!=NULL)
            {
                curr->next->prev=prevNode;
            }
            prevNode->next=curr->next;
            curr->next=NULL;
            curr->prev=NULL;
            delete curr;
        }
    }
}
void display(Node * & head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* newNode=new Node(10);
    Node * head=newNode;
    Node * tail=newNode;
    insertattail(head,tail,20);
    insertattail(head,tail,30);
    insertattail(head,tail,40);
    insertatposition(head,tail,25,3);
    display(head);
    insertattail(head,tail,50);
    display(head);
    deletenode(head,3);
    display(head);
    return 0;
}