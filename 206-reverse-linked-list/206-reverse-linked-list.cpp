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


class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *headNode = head;
        ListNode *newHead = nullptr;
        ListNode *nextNode = nullptr;
        while (headNode != nullptr) {
            nextNode = headNode->next;
            headNode->next = newHead;
            newHead = headNode;
            headNode = nextNode;
        }
        return newHead;
    }
};
