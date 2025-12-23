#include <iostream>
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
    // Helper function to find the total length of the list
    int getlength(ListNode* head) {
        int len1 = 0;
        while (head != NULL) {
            head = head->next;
            len1++;
        }
        return len1;
    }

    ListNode* middleNode(ListNode* head) {
        int length = getlength(head);
        int ans = (length / 2);
        
        ListNode* temp = head;
        int cnt = 0;
        while (cnt < ans) {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};

// Utility function to print the list starting from a given node
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 1. Create a linked list: 10 -> 20 -> 30 -> 40 -> 50
    ListNode* node5 = new ListNode(50);
    ListNode* node4 = new ListNode(40, node5);
    ListNode* node3 = new ListNode(30, node4);
    ListNode* node2 = new ListNode(20, node3);
    ListNode* head = new ListNode(10, node2);

    cout << "Original List: ";
    display(head);

    // 2. Find the middle node
    Solution sol;
    ListNode* middle = sol.middleNode(head);

    // 3. Output the result
    if (middle != nullptr) {
        cout << "The value of the middle node is: " << middle->val << endl;
        cout << "List starting from middle: ";
        display(middle);
    }

    return 0;
}
