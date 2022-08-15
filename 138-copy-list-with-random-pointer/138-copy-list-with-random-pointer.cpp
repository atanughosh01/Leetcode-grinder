/*
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };
*/


// O(N) time, O(N) space solution, N = length of list
class Solution_1 {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node*, Node*> mp;
        Node *curr = head;
        while (curr != nullptr) {
            Node *copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};




// O(N) time, O(1) space solution, N = length of list
class Solution {
private:
    // creates a copy of the list with only next pointers but no random pointers
    void copyList(Node *head) {
        Node *cur = head, *nxt = head->next;
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            cur->next = copy;
            copy->next = nxt;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }
    }

    // creates random pointers in the copied list, similar to the original list
    void handleRandomPtr(Node *head) {
        Node *cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
    }

    // separates the two lists and returns head of the newly deep-copied list
    Node *detachLists(Node *head) {
        Node *cur = head;
        Node *dummy = new Node(-1);
        dummy->next = cur->next;
        Node *tail = dummy->next;
        while (cur != nullptr) {
            cur->next = cur->next->next;
            cur = cur->next;
            if (tail->next != nullptr) {
                tail->next = tail->next->next;
            }
            tail = tail->next;
        }
        return dummy->next;
    }

public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return head;
        copyList(head);
        handleRandomPtr(head);
        return detachLists(head);
    }
};
