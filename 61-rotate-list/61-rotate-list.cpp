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
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *tail = head;
        int len = 0; len++;
        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }
        if (k % len == 0) return head;
        k = len - (k % len);
        ListNode *newTail = head;
        while (k > 1) {
            newTail = newTail->next;
            k--;
        }
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
