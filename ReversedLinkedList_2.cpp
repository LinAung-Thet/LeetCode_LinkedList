#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* n) : val(x), next(n){}
    ListNode(ListNode* ln) : val(ln->val), next(ln->next){}
};
class Solution{
public :
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move `prev` to the node before `left`
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from `left` to `right`
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left; ++i) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
int main(){
    Solution solution;
    ListNode* head;
    int left, right;

    cout << "Test case 1" << endl;
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    left = 2; right = 4;
    head = solution.reverseBetween(head, left, right);
    cout << "Expected: 1 4 3 2 5" << endl;
    cout << "Result  : ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    head = new ListNode(5);
    left = 1; right = 1;
    head = solution.reverseBetween(head, left, right);
    cout << "Expected: 5" << endl;
    cout << "Result  : ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl;

    return 0;
}