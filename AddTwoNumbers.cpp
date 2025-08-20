// https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=linked-list

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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        long multiplier = 1;
        long num1 = 0, num2 = 0, sum = 0;
        while(l1){
            num1 += l1->val * multiplier;
            multiplier *= 10;
            l1 = l1->next;
        }
        multiplier = 1;
        while(l2){
            num2 += l2->val * multiplier;
            multiplier *= 10;
            l2 = l2->next;
        }
        sum = num1 + num2;

        ListNode* head = new ListNode(0, new ListNode(0));
        ListNode* prev = head;
        while(sum > 0) {
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            sum = sum / 10;
        }
        return head->next;
    }
};

int main(){
    Solution solution;
    ListNode* l1;
    ListNode* l2;
    ListNode* sum;
    int s = 0, m = 1;

    cout << "Test case 1" << endl;
    s = 0, m = 1;
    l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    sum = solution.addTwoNumbers(l1, l2);
    cout << "Expected: 807" << endl;
    cout << "Result  : ";
    while (sum) {
        s += sum->val * m;
        m *= 10;
        sum = sum->next;
    }
    cout << s << endl << endl;

    cout << "Test case 2" << endl;
    s = 0, m = 1;
    l1 = new ListNode();
    l2 = new ListNode();
    sum = solution.addTwoNumbers(l1, l2);
    cout << "Expected: 0" << endl;
    cout << "Result  : ";
    while (sum) {
        s += sum->val * m;
        m *= 10;
        sum = sum->next;
    }
    cout << s << endl << endl;

    cout << "Test case 3" << endl;
    s = 0, m = 1;
    l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, 
         new ListNode(9, new ListNode(9, new ListNode(9)))))));
    l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    sum = solution.addTwoNumbers(l1, l2);
    cout << "Expected: 10009998" << endl;
    cout << "Result  : ";
    while (sum) {
        s += sum->val * m;
        m *= 10;
        sum = sum->next;
    }
    cout << s << endl << endl;

    return 0;
}