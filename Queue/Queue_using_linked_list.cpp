/*
 queue using linked list
*/ 
#include<bits/stdc++.h>
using namespace std;
class Queue
{
    private:
    class Node
    {
        public:
        int data;
        Node* next;
        Node(int val):data(val),next(NULL) {}
    };
    Node *front;
    Node* rear;
    public:
    Queue():front(NULL),rear(NULL) {}
    void enqueue(int val)
    {
        Node * temp=new Node(val);
        if(rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node*temp=front;
        front=front->next;
        delete temp;
        if(front==NULL)
        {
            rear==NULL;
        }
    }
    bool isEmpty()
    {
        return !front;
    }
    int getfront()
    {
        return front ?front->data:-1;
    }
    ~Queue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }
    void display()
    {
        Node*temp=front;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    return 0;
}