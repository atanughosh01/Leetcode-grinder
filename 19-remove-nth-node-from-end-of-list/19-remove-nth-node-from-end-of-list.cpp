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


// O(2*n) time, O(1) space
class Solution_1 {
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


// O(n) time, O(1) space
class Solution_2 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *fast = preHead, *slow = preHead;
        int k = 0;
        while (fast != nullptr) {
            if (k <= n) k++;
            else slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
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
