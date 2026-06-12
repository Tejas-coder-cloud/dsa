/*
Swap k nodes in a linked list 
Time complexity:O(n)
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
Node *swapKth(Node *head, int k)
{
    // code here
    if (!head || k <= 0)
    {
        return head;
    }
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *left_prev = dummy;
    Node *fast = dummy;
    for (int i = 0; i < k; i++)
    {
        if (fast->next == NULL)
        {
            return head;
        }
        left_prev = fast;
        fast = fast->next;
    }
    Node *left = fast;
    Node *right_prev = dummy;
    Node *right = dummy->next;
    while (fast->next)
    {
        fast = fast->next;
        right_prev = right;
        right = right->next;
    }
    if (left == right)
    {
        return head;
    }
    if (left->next == right)
    {
        left_prev->next = right;
        left->next = right->next;
        right->next = left;
    }
    else if (right->next == left)
    {
        right_prev->next = left;
        right->next = left->next;
        left->next = right;
    }
    else
    {
        left_prev->next = right;
        right_prev->next = left;
        Node *temp = left->next;
        left->next = right->next;
        right->next = temp;
    }
    Node *result = dummy->next;
    delete dummy;
    return result;
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
    cout << "NULL";
    cout << endl;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = createlist(v);
    display(head);
    Node* result=swapKth(head,1);
    display(result);
    return 0;
}