#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;
    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
  public:
    Node* merge(Node* head1, Node* head2) {
        Node* head = new Node(0);
        Node* tail = head;
        while(head1 && head2) {
            if(head1->data <= head2->data) {
                tail->bottom = head1;
                head1 = head1->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
            }
            else {
                tail->bottom = head2;
                head2 = head2->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
            }
        }
        if(head1) {
            tail->bottom = head1;
        }
        else {
            tail->bottom = head2;
        }
        return head->bottom;
    }
    
    Node *flatten(Node *root) {
        Node* head1, *head2, *head3;
        while(root->next) {
            head1 = root;
            head2 = root->next;
            head3 = root->next->next;
            head1->next = NULL;
            head2->next = NULL;
            root = merge(head1, head2);
            root->next = head3;
        }
        return root;
    }
};

// ========== HELPER FUNCTIONS ==========

// Print the flattened list (vertical chain)
void printFlattened(Node* head) {
    cout << "Flattened list: ";
    while(head) {
        cout << head->data << " -> ";
        head = head->bottom;
    }
    cout << "NULL\n";
}

// Print 2D structure for visualization
void print2DStructure(Node* root) {
    cout << "\n2D Structure:\n";
    Node* horizontal = root;
    int row = 0;
    while(horizontal) {
        cout << "Row " << row << ": ";
        Node* vertical = horizontal;
        while(vertical) {
            cout << vertical->data << " ";
            vertical = vertical->bottom;
        }
        cout << "\n";
        horizontal = horizontal->next;
        row++;
    }
}

// ========== MAIN FUNCTION ==========

int main() {
    Solution solution;
    
    // ===== TEST CASE 1: 3x3 Grid =====
    cout << "===== TEST CASE 1: 3x3 Grid =====\n";
    
    // Create structure:
    // 5  -> 10 -> 19 -> 28
    // |     |     |     |
    // 7     20    22    33
    // |     |     |
    // 8     50    40
    // |           |
    // 30          45
    
    // Row 0
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);
    
    // Row 1
    root->next = new Node(10);
    root->next->bottom = new Node(20);
    root->next->bottom->bottom = new Node(50);
    
    // Row 2
    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(40);
    root->next->next->bottom->bottom->bottom = new Node(45);
    
    // Row 3
    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(33);
    
    print2DStructure(root);
    
    Node* flattened = solution.flatten(root);
    printFlattened(flattened);
    
    // ===== TEST CASE 2: Single Row =====
    cout << "\n===== TEST CASE 2: Single Row =====\n";
    
    // 1 -> 2 -> 3
    Node* root2 = new Node(1);
    root2->next = new Node(2);
    root2->next->next = new Node(3);
    
    print2DStructure(root2);
    Node* flattened2 = solution.flatten(root2);
    printFlattened(flattened2);
    
    // ===== TEST CASE 3: Single Column =====
    cout << "\n===== TEST CASE 3: Single Column =====\n";
    
    // 1
    // |
    // 2
    // |
    // 3
    Node* root3 = new Node(1);
    root3->bottom = new Node(2);
    root3->bottom->bottom = new Node(3);
    
    print2DStructure(root3);
    Node* flattened3 = solution.flatten(root3);
    printFlattened(flattened3);
    
    return 0;
}