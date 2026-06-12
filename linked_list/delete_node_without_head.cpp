/*
Delete a node without using head pointer
Time complexity:O(1)
Space complexity:O(1)
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
void deleteNode(Node *del_node)
{
    Node *forward = del_node->next;
    del_node->data = forward->data;
    del_node->next = forward->next;
    delete forward;
}
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
void display(Node *&head)
{
    Node *temp = head;
    cout << "Linked list is as follows ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout << endl;
}
int main()
{
    vector<int> v = {1,2,3,4,5};
    Node *head = createlist(v);
    display(head);
    deleteNode(head->next->next);
    display(head);
    return 0;
}