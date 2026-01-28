#include<bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
    public:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) 
    {
        if (curr == NULL) 
        {
            head = prev; 
            return;
        }
        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
    }
};
void display(ListNode* head) 
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() 
{
    ListNode* node4 = new ListNode(40);
    ListNode* node3 = new ListNode(30, node4);
    ListNode* node2 = new ListNode(20, node3);
    ListNode* head = new ListNode(10, node2);
    cout << "Original Linked List: " << endl;
    display(head);
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "Reversed Linked List: " << endl;
    display(reversedHead);
    return 0;
}