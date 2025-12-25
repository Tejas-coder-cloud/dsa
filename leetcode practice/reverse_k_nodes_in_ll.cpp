#include <iostream>
#include <vector>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Check if there are at least k nodes available
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == nullptr) { 
                return head; // Not enough nodes to reverse, return as is
            }
            check = check->next;
        }

        // 2. Standard reversal logic for the current group of k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int cnt = 0;

        while (curr != nullptr && cnt < k) {
            next = curr->next;
            curr->next = prev; // Flipping the pointer
            prev = curr;       // Moving prev forward
            curr = next;       // Moving curr forward
            cnt++;
        }

        // 3. Recursive call: Connect the tail of our reversed group 
        // (the original 'head') to the result of the next group
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // 'prev' is now the new head of this reversed segment
        return prev;
    }
};

// --- Helper Functions for testing ---

// Creates a linked list from a vector of integers
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < nums.size(); i++) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

// Prints the linked list in a readable format
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Test Case: List = [1, 2, 3, 4, 5], k = 2
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