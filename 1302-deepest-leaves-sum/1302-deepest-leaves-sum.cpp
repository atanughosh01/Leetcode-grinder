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

class Solution {
public:
    void dfs(TreeNode* root, int n, int &deepestSum, int &h){
        if (!root) return;
        if (n==h) deepestSum+=root->val;
        if (n > h) {
            deepestSum = root->val;
            h = n;
        }
        dfs(root->left, n+1, deepestSum, h);
        dfs(root->right, n+1, deepestSum, h);
    }
    int deepestLeavesSum(TreeNode* root) {
        int deepestSum = 0, h = 1;
        dfs(root, 1, deepestSum, h);
        return deepestSum;
    }
};
