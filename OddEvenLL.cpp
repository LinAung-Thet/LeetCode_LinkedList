// https://leetcode.com/problems/odd-even-linked-list/description/?envType=problem-list-v2&envId=linked-list

#include <iostream>
using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        ListNode* first = head, *second = head->next;
        ListNode* odd = first, *even = second;

        while (even->next && even->next->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        if (even->next) {
            odd->next = even->next;
            odd = odd->next;
        }
        even->next = nullptr;

        // merge the odd list and even list
        odd->next = second;
        
        return first;
    }
};

int main() {
    Solution solution;
    ListNode* head;

    cout << "Test case 1" << endl;
    cout << "Input   : 1 2 3 4 5" << endl;
    cout << "Expected: 1 3 5 2 4" << endl;
    cout << "Result  :";
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head = solution.oddEvenList(head);
    while (head) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    cout << "Input   : 2 1 3 5 6 4 7" << endl;
    cout << "Expected: 2 3 6 7 1 5 4" << endl;
    cout << "Result  :";
    head = new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(7)))))));
    head = solution.oddEvenList(head);
    while (head) {
        cout << " " << head->val;
        head = head->next;
    }
}