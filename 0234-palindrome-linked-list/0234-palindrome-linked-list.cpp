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

// O(n) time, O(n) space, n = length of LL
class Solution_1 {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *temp = head;
        vector<int> nodes;
        while (temp != nullptr) {
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        int n = (int)(nodes.size());
        for (int i = 0; i < n/2; i++) {
            if (nodes[i] != nodes[n - 1 -i]) {
                return false;
            }
        }
        return true;
    }
};


// O(n) time, O(1) space, n = length of LL
class Solution_2 {
private:
    ListNode *reversePartOfList(ListNode *list) {
        ListNode *prv = nullptr;
        ListNode *cur = list;
        ListNode *nxt = list->next;
        while (cur != nullptr) {
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }
        return prv;
    }

    ListNode *getMiddleOfList(ListNode *list) {
        ListNode *slow = list, *fast = list;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head->next == nullptr) {
            return true;
        }
        
        ListNode *start = head;
        ListNode *mid = getMiddleOfList(start);
        ListNode *end = reversePartOfList(mid->next);
        mid->next = end;
        
        ListNode *p1 = start, * p2 = mid->next;
        
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};


// O(n) time, O(1) space, n = length of LL
class Solution {
private:
    ListNode *reversePartOfList(ListNode *list) {
        ListNode *prv = nullptr;
        ListNode *cur = list;
        ListNode *nxt = list->next;
        while (cur != nullptr) {
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }
        return prv;
    }

    ListNode *getMiddleOfList(ListNode *list) {
        ListNode *slow = list, *fast = list;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head->next == nullptr) {
            return true;
        }
        
        ListNode *start = head;
        ListNode *mid = getMiddleOfList(start);
        ListNode *end = reversePartOfList(mid->next);
        mid->next = end;
        
        ListNode *p1 = start, *p2 = mid->next;
        bool res = true;
        
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                res = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // Restructure the linked-list by re-rotating the rotated portion
        end = reversePartOfList(mid->next);
        mid->next = end;
        
        return res;
    }
};
