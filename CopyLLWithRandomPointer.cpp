#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* random;

    ListNode() : val(0), next(nullptr), random(nullptr){}
    ListNode(int x) : val(x), next(nullptr), random(nullptr){}
    ListNode(int x, ListNode* n) : val(x), next(n), random(nullptr){}
    ListNode(ListNode* ln) : val(ln->val), next(ln->next), random(nullptr){}
};
class Solution{
public :
    ListNode* copyRandomList(ListNode* head) {
        if (!head) return nullptr;

        unordered_map<ListNode*, ListNode*> nodeMap;

        // Step 1: Create all nodes and store mapping
        ListNode* curr = head;
        while (curr) {
            nodeMap[curr] = new ListNode(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }

        return nodeMap[head];
    }
};
int main(){
    
    return 0;
}