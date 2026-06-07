/* 
Remove duplicates from a sorted linked list
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
Node* remove(Node *&head)
{
    Node* curr=head;
    while(curr)
    {
        if((curr->next!=NULL) && (curr->data ==curr->next->data))
        {
            Node* next_next=curr->next->next;
            Node* nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
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
    cout << endl;
}
int main()
{
    vector<int> v = {1,2,2,3,5};
    Node *head = createlist(v);
    display(head);
    Node* newHead=remove(head);
    display(newHead);
    return 0;
}