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
bool Detectloop(Node * &head)
{   map<Node*,bool> visited;
    Node*temp=head;
    if(head==NULL)
    {
        return false;
    }
 
    while(temp!=NULL)
    {
        
        if(visited[temp]==true)
        {
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
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
    if(Detectloop(head))
    {
        cout<<"Linked list contains a loop"<<endl;
    }
    else
    {
        cout<<"Linked list doesn't contain a loop"<<endl;
    }
    return 0;
}
