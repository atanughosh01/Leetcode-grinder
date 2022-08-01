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


// O(n) time, O(n) space
class SolutionRecursive {
public:
    ListNode* removeElements(ListNode *head, int target) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, target);
        return head ->val == target ? head->next : head;
    }
};


// O(n) time, O(1) space
class Solution {
public:
    ListNode* removeElements(ListNode *head, int target) {
        if (head == nullptr) return head;
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *tail = preHead;
        while (tail != nullptr && tail->next != nullptr) {
            if (tail->next->val == target) {
                ListNode *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            } else {
                tail = tail->next;
            }
        }
        return preHead->next;
    }
};
