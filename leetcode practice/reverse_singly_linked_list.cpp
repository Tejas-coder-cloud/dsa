#include <bits/stdc++.h>
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;  
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        while(curr != nullptr) 
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};
void printList(ListNode* head) 
{
    while (head != nullptr) 
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() 
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);
    cout << "Original List: ";
    printList(head);
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "Reversed List: ";
    printList(reversedHead);
    return 0;
}