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


class Solution_1 {
private:
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

public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return nullptr;
        int k = (int)(lists.size());
        ListNode *merged = lists[0];
        for (int i = 1; i < k; i++) {
            merged = mergeTwoLists(merged, lists[i]);
        }
        return merged;
    }
};



class Solution_2 {
private:
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

public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return nullptr;
        int k = (int)(lists.size());
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        return lists.front();
    }
};




// O(nlog(k)) time, n = avg length of LL, k = lists.length, O(n * k)
class SolutionWithMeanHeap {
private:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (!pq.empty()) {
            ListNode *temp = pq.top();
            tail->next = temp;
            tail = temp;
            pq.pop();
            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }
        tail->next = nullptr;
        return dummy->next;
    }
};



// O(nlog(k)) time, n = avg length of LL, k = lists.length, O(n * k)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return nullptr;
        map<int, int> nodeFreq;
        for (int i = 0; i< lists.size(); i++) {
            ListNode *node = lists[i];
            while (node != nullptr) {
                nodeFreq[node->val]++;
                node = node->next;
            }
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        for (auto it : nodeFreq) {
            while (it.second != 0) {
                ListNode *newNode = new ListNode(it.first);
                tail->next = newNode;
                tail = tail->next;
                it.second--;
            }
        }
        return dummy->next;
    }
};
