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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* check = head;
        for (int i = 0; i < k; i++) 
        {
            if (check == nullptr) 
            { 
                return head; 
            }
            check = check->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int cnt = 0;
        while (curr != nullptr && cnt < k) 
        {
            next = curr->next;
            curr->next = prev; 
            prev = curr;       
            curr = next;       
            cnt++;
        }
        if (next != nullptr) 
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};
ListNode* createList(const vector<int>& nums) 
{
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < nums.size(); i++) 
    {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}
void printList(ListNode* head) 
{
    while (head) 
    {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}
int main() 
{
    Solution sol;
    vector<int> nodes = {1, 2, 3, 4, 5};
    int k = 2;
    ListNode* head = createList(nodes);
    cout << "Original List: ";
    printList(head);
    cout << "Value of k: " << k << endl;
    ListNode* result = sol.reverseKGroup(head, k);
    cout << "Modified List: ";
    printList(result);
    return 0;
}