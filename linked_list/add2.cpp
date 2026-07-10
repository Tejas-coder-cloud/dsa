/*
Add  2  linked lists
n=Length of first linked list 
m=Length of second linked list
Time complexity:O(n+m)
Space complexity:O(max(n+m)+1)
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
    Node* temp=new Node(v[0]);
    Node* curr=temp;
    for (int i = 1; i < v.size(); i++)
    {
        curr->next=new Node(v[i]);
        curr=curr->next;
    }
    return temp;
}
Node* reverse(Node*& head) 
{
    Node* prev = NULL;
    Node* curr = head;
    if(head ==NULL || head->next==NULL)
    {
        return head;
    }
    while (curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node* add2(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    l1 = reverse(l1);
    l2 = reverse(l2);

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return reverse(dummy->next);
}
void display(Node*&head)
{
    Node*temp=head;
    cout<<"Linked list is as follows ";
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;  
}
int main() 
{
    vector<int> v1={1,2,3};
    vector<int> v2={1,2,3};
    Node* head1=createlist(v1);
    display(head1);
    Node* head2=createlist(v2);
    display(head2);
    Node* newHead=add2(head1,head2);
    display(newHead);
    return 0;
}