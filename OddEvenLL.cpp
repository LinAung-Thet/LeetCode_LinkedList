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
