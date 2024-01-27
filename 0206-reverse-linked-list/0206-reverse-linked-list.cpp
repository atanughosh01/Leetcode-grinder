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


// Iterative (better bcz no stack space is needed for recursive call)
class Solution_1 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *currHead = head;
        ListNode *newHead = nullptr;
        ListNode *nextNode = nullptr;
        while (currHead != nullptr) {
            nextNode = currHead->next;
            currHead->next = newHead;
            newHead = currHead;
            currHead = nextNode;
        }
        return newHead;
    }
};


// Recursive solution
class Solution {
private:
    ListNode *reverse(ListNode *headNode) {
        if (headNode->next == nullptr) return headNode;
        ListNode *reverseHead = reverse(headNode->next);
        headNode->next->next = headNode;
        headNode->next = nullptr;
        return reverseHead;
    }
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return nullptr;
        return reverse(head);
    }
};
