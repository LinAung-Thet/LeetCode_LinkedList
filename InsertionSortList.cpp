// https://leetcode.com/problems/insertion-sort-list/description/?envType=problem-list-v2&envId=linked-list

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* n) : val(x), next(n){}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = &dummy;
            ListNode* nextNode = curr->next;

            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert the current node between prev and the following node
            curr->next = prev->next;
            prev->next = curr;

            // Move curr to the next node in the original sequence
            curr = nextNode;
        }
  
        // return the result
        return dummy.next;
    }
};

int main() {
    Solution solution;
    ListNode* head;

    cout << "Test case 1" << endl;
    head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head = solution.insertionSortList(head);
    cout << "Input   : 4 2 3 1" << endl;
    cout << "Expected: 1 2 3 4" << endl;
    cout << "Result  :";
    while (head) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
    head = solution.insertionSortList(head);
    cout << "Input   : -1 5 3 4 0" << endl;
    cout << "Expected: -1 0 3 4 5" << endl;
    cout << "Result  :";
    while (head) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl << endl;

    return 0;
}