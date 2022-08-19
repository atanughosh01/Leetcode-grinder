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
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr) return nullptr;
        ListNode *mid = head, *tail = head, *preMid = head;
        while (tail != nullptr && tail->next != nullptr) {
            preMid = mid;
            mid = mid->next;
            tail = tail->next->next;
        }
        preMid->next = mid->next;
        delete mid;
        return head;
    }
};
