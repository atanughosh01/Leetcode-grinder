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
    void reverseOneGroup(ListNode *left, ListNode *right) {
        ListNode *newLeft = nullptr;
        ListNode *currLeft = left;
        ListNode *nextOfLeft = left->next;
        while (newLeft != right) {
            currLeft->next = newLeft;
            newLeft = currLeft;
            currLeft = nextOfLeft;
            if (nextOfLeft != nullptr) {
                nextOfLeft = nextOfLeft->next;
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
        ListNode *headOfNextGrp = reverseKGroup(end->next, k);
        reverseOneGroup(start, end);
        start->next = headOfNextGrp;
        return end;
    }
};
