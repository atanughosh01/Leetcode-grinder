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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre = head, *tail = head;
        int len = 0;
        while (tail != nullptr) {
            len++;
            tail = tail->next;
        }
        if (len == n) {
            return head->next;
        }
        int m = len - n - 1;
        while (m--) {
            pre = pre->next;
        }
        ListNode *temp = pre->next;
        pre->next = temp->next;
        delete temp;
        return head;
    }
};
