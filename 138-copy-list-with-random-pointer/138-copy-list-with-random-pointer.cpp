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
class Solution {
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
