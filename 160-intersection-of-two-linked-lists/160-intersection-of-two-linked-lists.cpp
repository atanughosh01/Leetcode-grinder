/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Most bruteforce, O(A.len * B.len) time, O(1) space
class BruteForce {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != nullptr) {
            b = headB;
            while (b != nullptr) {
                if (a == b) return a;
                b = b->next;
            }
            a = a->next;
        }
        return nullptr;
    }
};



// O(A.len * B.len) time, O(1) space
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *a = headA, *b = headB;
        while (a != nullptr) {
            lenA++;
            a = a->next;
        }
        while (b != nullptr) {
            lenB++;
            b = b->next;
        }
        a = headA, b = headB;
        if (lenA > lenB) {
            swap(lenA, lenB);
            swap(a, b);
        }
        while (lenB != lenA) {
            lenB--;
            b = b->next;
        }
        while (a != nullptr && b != nullptr) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
