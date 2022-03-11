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



/*
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head)
                return head;

            int len = 1; // number of nodes
            ListNode *newH, *tail;
            newH = tail=head;

            while(tail->next) { // get the number of nodes in the list
                tail = tail->next;
                len++;
            }
            tail->next = head; // circle the link

            if(k %= len) {
                for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
            }

            newH = tail->next; 
            tail->next = NULL;
            return newH;
        }
    };
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int listNum = 1;
        ListNode* tail = head;
        
        while(tail->next != NULL){
            listNum++;
            tail = tail->next;
        }
        tail->next = head;
        int newHeadIndex = listNum - k % listNum;

        for(int i = 0; i < newHeadIndex; i++){
            tail = tail->next;
        }
        
        head = tail->next;
        tail->next = NULL;

        return head;
    }
};
