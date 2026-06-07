/* 
Remove duplicates from an unsorted linked list
Time complexity: O(n)
Space complexity: O(n)
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
    unordered_set<int> visited;
    Node* curr=head;
    Node* prev=NULL;
    while(curr)
    {
        if(visited.find(curr->data)!=visited.end())
        {
            prev->next=curr->next;
            Node* nodetodelete=curr;
            curr=curr->next;
            delete(nodetodelete);
        }
        else
        {
            visited.insert(curr->data);
            prev=curr;
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
    vector<int> v = {1,2,3,2,0,1,3};
    Node *head = createlist(v);
    display(head);
    Node* newHead=remove(head);
    display(newHead);
    return 0;
}