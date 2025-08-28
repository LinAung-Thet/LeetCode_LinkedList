// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/?envType=problem-list-v2&envId=linked-list

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = getSize(head);
        current = head;
        return buildBST(0, size - 1);
    }

private:
    ListNode* current;

    int getSize(ListNode* head) {
        int count = 0;
        while (head) {
            ++count;
            head = head->next;
        }
        return count;
    }

    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = buildBST(left, mid - 1);

        TreeNode* node = new TreeNode(current->val);
        node->left = leftChild;
        current = current->next;

        node->right = buildBST(mid + 1, right);
        return node;
    }
};

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main(){
    Solution solution;
    ListNode* head;
    TreeNode* root;

    cout << "Test case 1" << endl;
    head = new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9)))));
    cout << "Expected: 0 -3 9 -10 null 5" << endl;
    cout << "Result  : "; 
    printLevelOrder(solution.sortedListToBST(head));
    cout << endl << endl;

    return 0;
}
