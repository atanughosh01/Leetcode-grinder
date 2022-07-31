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


// O(l1.len + l2.len) time, O(l1.len + l2.len) stack space
class SolutionRecursive {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
};



// O(l1.len + l2.len) time, O(l1.len + l2.len) space
class SolutionIterativeWithExtraSpace {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *preHead = new ListNode(-101);
        ListNode *tail = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;                
            }
        }
        if (l1 == nullptr) tail->next = l2;
        else tail->next = l1;
        return preHead->next;
    }
};



// O(l1.len + l2.len) time, O(1) space
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode *res = l1;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *temp = nullptr;
            while (l1 != nullptr && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
};
