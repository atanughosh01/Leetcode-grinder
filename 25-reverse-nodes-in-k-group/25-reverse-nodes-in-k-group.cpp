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


// Recursive, stack space wastage, O(n) time, O(n/k) stack space
class Solution_1 {
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



// Iterative, O(n) time, O(1) space;
class Solution {
private:
    void reverseGroup(ListNode *left, ListNode *right) {
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
        if (head->next == nullptr || k == 1) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *preStart = dummy, *postEnd = head;
        ListNode *start = head, *end = head;
        int grpLen = 0;

        while (end != nullptr) {
            grpLen++;
            
            if (grpLen % k == 0) {
                start = preStart->next;
                postEnd = end->next;
                
                reverseGroup(start, end);
                
                preStart->next = end;
                start->next = postEnd;
                preStart = start;
                end = postEnd;
            } else {
                end = end->next;
            }
        }
        return dummy->next;
    }
};
