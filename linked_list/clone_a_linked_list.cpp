#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node() : data(0), next(NULL), random(NULL) {}
    Node(int val) : data(val), next(NULL), random(NULL) {}
    Node(int val, Node *next) : data(val), next(next), random(NULL) {}
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

void printList(Node *head)
{
    while (head)
    {
        cout << "Data = " << head->data;

        if (head->random)
            cout << ", Random = " << head->random->data;
        else
            cout << ", Random = NULL";

        cout << endl;

        head = head->next;
    }
}

class Solution
{
public:
    void insertattail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    Node *cloneLinkedList(Node *head)
    {
        Node *clonehead = NULL;
        Node *clonetail = NULL;

        Node *temp = head;

        // Create clone list
        while (temp)
        {
            insertattail(clonehead, clonetail, temp->data);
            temp = temp->next;
        }

        // Insert clone nodes between original nodes
        Node *originalnode = head;
        Node *clonenode = clonehead;

        while (originalnode && clonenode)
        {
            Node *next = originalnode->next;
            originalnode->next = clonenode;
            originalnode = next;

            next = clonenode->next;
            clonenode->next = originalnode;
            clonenode = next;
        }

        // Copy random pointers
        temp = head;

        while (temp)
        {
            if (temp->next)
            {
                temp->next->random =
                    temp->random ? temp->random->next : NULL;
            }

            temp = temp->next->next;
        }

        // Separate both lists
        originalnode = head;
        clonenode = clonehead;

        while (originalnode && clonenode)
        {
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;

            if (originalnode)
            {
                clonenode->next = originalnode->next;
            }

            clonenode = clonenode->next;
        }

        return clonehead;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};

    Node *head = createlist(v);

    // Assign random pointers
    head->random = head->next->next;               // 1 -> 3
    head->next->random = head;                     // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4
    head->next->next->next->random = head->next;  // 4 -> 2

    cout << "Original List:\n";
    printList(head);

    Solution obj;

    Node *cloneHead = obj.cloneLinkedList(head);

    cout << "\nCloned List:\n";
    printList(cloneHead);

    return 0;
}