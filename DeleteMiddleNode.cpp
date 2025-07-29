// https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;  // List of size 1 → becomes empty

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find middle using slow and fast pointers
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

// Test cases
int main() {
    Solution sol;
    ListNode* head;

    cout << "Test case 1" << endl;
    cout << "Expected: 1 3 4 1 2 6" << endl;
    head = new ListNode(1, new ListNode(3, new ListNode(
        4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));
    head = sol.deleteMiddle(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl; 

    cout << "Test case 2" << endl;
    cout << "Expected: 1 2 4" << endl;
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    head = sol.deleteMiddle(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl; 

    cout << "Test case 3" << endl;
    cout << "Expected: 2" << endl;
    head = new ListNode(2, new ListNode(1));
    head = sol.deleteMiddle(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl; 

    cout << "Test case 4" << endl;
    cout << "Expected: " << endl;
    head = new ListNode(1);
    head = sol.deleteMiddle(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl; 


    return 0;
}