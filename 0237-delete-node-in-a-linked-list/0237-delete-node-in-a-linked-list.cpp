/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */


class Solution {
public:
    void deleteNode(ListNode *node) {
        if (!node->next) delete node;
        ListNode *postNode = node->next;
        swap(postNode->val, node->val);
        node->next = postNode->next;
        postNode->next = nullptr;
        delete postNode;
    }
};
