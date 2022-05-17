/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
private:
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &resultNode){
        if (!original || resultNode) return;
        if (original==target) resultNode = cloned;
        if (original->left) dfs(original->left,cloned->left,target,resultNode);
        if (original->right) dfs(original->right,cloned->right,target,resultNode);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* resultNode(nullptr);
        dfs(original,cloned,target,resultNode);
        return resultNode;
    }
};
