/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct Node {
    TreeNode *n;
    int x, y;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> mp;
        queue<Node *> q;
        q.push(new Node{root, 0, 0});
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (node->n->left) {
                q.push(new Node{node->n->left, node->x - 1, node->y + 1});
            }
            if (node->n->right) {
                q.push(new Node{node->n->right, node->x + 1, node->y + 1});
            }
            mp[node->x][node->y].push_back(node->n->val);
        }
        for (pair<int, map<int, vector<int>>> p1 : mp) {
            res.push_back({});
            for (pair<int, vector<int>> p2 : p1.second) {
                vector<int> v = p2.second;
                sort(v.begin(), v.end());
                res.back().insert(res.back().end(), v.begin(), v.end());
            }
        }
        return res;
    }
};
