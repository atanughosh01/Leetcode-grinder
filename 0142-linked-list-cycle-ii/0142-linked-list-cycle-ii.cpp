/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// O(n) time, O(n) space
class Solution_1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> nodeFreq;
        ListNode* node = head;
        while (node != nullptr) {
            if (nodeFreq[node] == 0) {
                nodeFreq[node]++;
            } else {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }
};



// O(n) time, O(1) space
class Solution_2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast != slow) return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


// O(n) time, O(1) space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
