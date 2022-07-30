/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
private:
    void reverseFirstGroup(ListNode *left, ListNode *right) {
        ListNode *prv = nullptr;
        ListNode *cur = left;
        ListNode *nxt = left->next;
        while (prv != right) {
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *start = head, *end = head;
        for (int i = 1; i < k; i++) {
            end = end->next;
            if (end == nullptr) return head;
        }
        ListNode *headOfNext = reverseKGroup(end->next, k);
        reverseFirstGroup(start, end);
        start->next = headOfNext;
        return end;
    }
};
