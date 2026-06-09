/* 
Rotate a linked list to the left by k positions
Time complexity: O(n)
Space complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int val) : data(val), next(NULL) {}
    Node(int val, Node *next) : data(val), next(next) {}
};
Node *createlist(vector<int> &v)
{
    Node *temp = new Node(v[0]);
    Node *curr = temp;
    for (int i = 1; i < v.size(); i++)
    {
        curr->next = new Node(v[i]);
        curr = curr->next;
    }
    return temp;
}
Node * rotate(Node* & head,int k)
{
    Node* curr=head;
    int len=1;
    while(curr->next && ++len)
    {
        curr=curr->next;
    }
    curr->next=head;
    k=k%len;
    if(k==0)
    {
        return head;
    }
    for(int i=0;i<k-1;i++)
    {
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;
    return head;
}
void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    Node *temp = head;
    cout << "Linked list is as follows: ";
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout << endl;
}
int main()
{
    vector<int> v = {1,2,3};
    Node *head = createlist(v);
    display(head);
    int k=1;
    Node* ans=rotate(head,2);
    display(ans);
    return 0;
}