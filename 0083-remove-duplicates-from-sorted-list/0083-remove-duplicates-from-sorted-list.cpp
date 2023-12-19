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


// Recursive, O(n) time, O(n) space
class Solution_Recursive {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *newHead = deleteDuplicates(head->next);
        if (head->val == newHead->val) {
            return newHead;
        }
        head->next = newHead;
        return head;
    }
};


// Iterative, O(n) time, O(1) space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *currHead = head;
        while (currHead->next != nullptr) {
            if (currHead->val == currHead->next->val) {
                ListNode *del = currHead->next;
                currHead->next = del->next;
                delete del;
            } else {
                currHead = currHead->next;
            }
        }
        return head;
    }
};
