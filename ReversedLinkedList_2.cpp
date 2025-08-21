#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* n) : val(x), next(n){}
};
class Solution{
public :
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        
        int i = 1;
        ListNode* curr = head;
        ListNode* pfx;
        while (i < left && curr) {
            pfx = curr;
            curr = curr->next;
            ++i;
        }
        ListNode* tail = curr;  // tail of the reversed part
        ListNode* prev;
        ListNode* buff;
        while (i < right) {
            buff = curr->next;
            prev = curr;        // 1
            curr = curr->next;
            curr->next = prev;
            curr = buff;
            ++i;
        }
        pfx->next = prev;   // head of the reversed part
        tail->next = curr;
    }
};
int main(){
    Solution solution;
    ListNode* head;
    int left, right;

    cout << "Test case 1" << endl;
    head = new ListNode(5);
    left = 1; right = 1;
    cout << "Expected: 5" << endl;
    cout << "Result  : ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << endl;

    return 0;
}