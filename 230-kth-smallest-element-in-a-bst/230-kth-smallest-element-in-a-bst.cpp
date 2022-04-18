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


/*
    // Recursive
    class Solution {
    private:
        int res = 0;
    public:
        void inorder(TreeNode* root, int& k) {
            if (!root)
                return;
            inorder(root->left, k);
            if (--k == 0)
                res = root->val;
            inorder(root->right, k);
        }
        int kthSmallest(TreeNode* root, int k) {
            inorder(root, k);
            return res;
        }
    };
*/


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
        return -1;
    }
};
