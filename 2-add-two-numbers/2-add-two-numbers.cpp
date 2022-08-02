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


class Solution_Recursive {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        int sum = l1->val + l2->val;
        ListNode *newNode = new ListNode(sum % 10);
        newNode->next = addTwoNumbers(l1->next, l2->next);
        
        if (sum > 9) {
            int carry = sum / 10;
            ListNode *carryNode = new ListNode(carry);
            newNode->next = addTwoNumbers(newNode->next, carryNode);
        }
        
        return newNode;
    }
};



// O(max(l1.len, l2.len)) time, O(max(l1.len, l2.len)) space
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *preHead = new ListNode(0);
        ListNode *temp = preHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
        }
        return preHead->next;
    }
};
