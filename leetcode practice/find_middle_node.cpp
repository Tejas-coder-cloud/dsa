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
/*
// Optimized approach
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

class Solution 
{
public:
    ListNode* middlepointer(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) 
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) 
        {
            fast = fast->next;
            if (fast != NULL) 
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    ListNode* middleNode(ListNode* head) 
    {
        return middlepointer(head);
    }
};

// --- Helper Functions for main() ---

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print the list starting from a specific node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: Odd number of elements [1, 2, 3, 4, 5]
    vector<int> data1 = {1, 2, 3, 4, 5};
    ListNode* list1 = createList(data1);
    
    cout << "Original List 1: ";
    printList(list1);

    ListNode* mid1 = sol.middleNode(list1);
    cout << "Middle Node starts at: " << mid1->val << endl;
    cout << "Full list from middle: ";
    printList(mid1);

    cout << "\n-------------------\n" << endl;

    // Example 2: Even number of elements [1, 2, 3, 4, 5, 6]
    vector<int> data2 = {1, 2, 3, 4, 5, 6};
    ListNode* list2 = createList(data2);

    cout << "Original List 2: ";
    printList(list2);

    ListNode* mid2 = sol.middleNode(list2);
    cout << "Middle Node starts at: " << mid2->val << endl;
    cout << "Full list from middle: ";
    printList(mid2);

    return 0;
}
*/