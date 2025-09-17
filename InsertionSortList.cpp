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
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head) {
            ListNode* nextNode = head->next;
            ListNode* temp = &dummy;

            // insert the current node at an appropriate position
            while (temp && temp->next != head) {
                if (head->val < temp->next->val) {
                    // insert the node
                    head->next = temp->next->next;
                    temp->next = head;

                    // remove the current node.
                    prev->next = head->next;

                    break;
                }
                temp = temp->next;
            }

            // move the pointer
            prev = head;
            head = nextNode;
        }

        // return the result
        return dummy.next;
    }
};