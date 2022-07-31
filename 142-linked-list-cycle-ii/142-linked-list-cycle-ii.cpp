/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> nodeFreq;
        ListNode* node = head;
        while (node != nullptr) {
            if (nodeFreq[node] == 0) {
                nodeFreq[node]++;
            } else {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }
};
