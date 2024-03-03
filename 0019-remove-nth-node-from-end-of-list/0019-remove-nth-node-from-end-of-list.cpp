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


class Solution_1 {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *preHead = new ListNode(-1);
        ListNode *temp = preHead->next;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }
        temp = head;
        len -= n - 1;
        while (len--) temp = temp->next;
        temp->next = temp->next->next;
        return preHead->next;
    }
};


// O(n) time, O(1) space, crisper code, less nodes
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (fast == nullptr) return head->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};
