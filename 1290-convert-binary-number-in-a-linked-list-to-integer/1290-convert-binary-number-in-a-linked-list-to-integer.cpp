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


// TC : O(n), SC : O(n), n = length of linked-list
class Solution_1 {
public:
    int getDecimalValue(ListNode *head) {
        int decimal = 0;
        ListNode *temp = head;
        vector<int> arr;
        while (temp) {
            int digit = temp->val;
            arr.push_back(digit);
            temp = temp->next;
        }
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int num = arr[i] * pow(2, n-i-1);
            decimal += num;
        }
        return decimal;
    }
};



// TC : O(n), SC : O(1), n = length of linked-list
class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int decimal = 0;
        ListNode *temp = head;
        while (temp) {
            decimal *= 2;
            decimal += temp->val;
            temp = temp->next;
        }
        return decimal;
    }
};
