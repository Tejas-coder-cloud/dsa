// recursive approach 
#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper function for recursion
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        // Base Case: If we reach the end of the list
        if (curr == NULL) {
            head = prev; // Update the head to the last non-null node
            return;
        }

        ListNode* forward = curr->next;
        
        // Recursive Call: Move to the next node
        reverse(head, forward, curr);
        
        // Backtracking: Flip the pointer direction
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
    }
};

// Function to print the linked list
// Pass by value (no &) to keep the head in main safe
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 1. Creating nodes: 10 -> 20 -> 30 -> 40
    ListNode* node4 = new ListNode(40);
    ListNode* node3 = new ListNode(30, node4);
    ListNode* node2 = new ListNode(20, node3);
    ListNode* head = new ListNode(10, node2);

    cout << "Original Linked List: " << endl;
    display(head);

    // 2. Reversing the list
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed Linked List: " << endl;
    display(reversedHead);

    return 0;
}