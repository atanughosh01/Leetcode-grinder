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


// Bruteforce, O(A.len + A.len) time, O(A.len) space
class SolutionHashmap {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        unordered_map<ListNode *, int> nodeFreq;
        while (a != nullptr) {
            nodeFreq[a]++;
            a = a->next;
        }
        a = headA;
        while (b != nullptr) {
            if (nodeFreq[b] == 0) {
                b = b->next;
            } else {
                return b;
            }
        }
        return b;
    }
};


// O(A.len + B.len) time, O(1) space
class SynchronizeTheLengths {
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


// O(A.len + B.len) time but much faster and crisp code, O(1) space, synchronize-the-lengths
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            if (a == nullptr) a = headB;
            else a = a->next;
            
            if (b == nullptr) b = headA;
            else b = b->next;
        }
        return a;
    }
};
