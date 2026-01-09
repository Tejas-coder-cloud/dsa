/*
stack using linked list
*/ 
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    private:
    class Node
    {
        public:
        int data;
        Node*next;
        Node(int value):data(value),next(NULL) {}
        
    };
    Node*top;
    public:
    Stack():top(NULL) {}
    ~Stack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    void push(int value)
    {
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        return;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty, Can't pop"<<endl;
            return;
        }
        Node*temp=top;
        top=top->next;
        delete temp;
        return;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty,"<<endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        else
        {
            Node *temp=top;
            cout<<"Stack is as follows: "<<endl;
            while(temp)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
            return;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<"The top element is: "<<s.peek()<<endl;
    s.pop();
    s.display();
    cout<<"The top element after poping is: "<<s.peek()<<endl;
    return 0;
}