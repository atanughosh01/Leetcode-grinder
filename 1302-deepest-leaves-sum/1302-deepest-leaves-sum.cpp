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
*/


/*
    class Solution {
    public:
        int deepestLeavesSum(TreeNode* root) {
            if (root==NULL) return 0;
            queue<TreeNode*> q;
            q.push(root);
            int sum = 0;
            while (!q.empty()) {
                int n = (int)(q.size()); 
                sum = 0;
                for (int i=0; i<n; i++){
                    TreeNode* front = q.front();
                    q.pop();
                    sum += front->val;
                    if (front->left != NULL)
                        q.push(front->left);
                    if (front->right != NULL)
                        q.push(front->right);
                }
            }
            return sum;
        }
    };
*/


class Solution {
private:
    int deepestLevel = 1, sum = 0;
    void traverse (TreeNode* root , int level){
        if (!root) return;
        if (level == deepestLevel){
            sum += root->val;
        }
        if (level > deepestLevel){
            deepestLevel = level;
            sum = root->val;
        }
        traverse(root->left, level +1);
        traverse(root->right, level + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        deepestLevel = 1, sum = 0;
        traverse(root, 1);
        return sum;
    }
};
