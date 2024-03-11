/*
    // Definition for a Node

    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
*/



class Solution {
private:
    vector<vector<int>> res;
    void rec(Node *root, int level) {
        if (root == nullptr) return;
        if (level == res.size()) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        for (Node *child : root->children) {
            rec(child, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node *root) {
        rec(root, 0);
        return res;
    }
};
