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
private:
   void helper(TreeNode *root, int &ans, int *map) {
        if(!root) return;
        map[root->val]++; 
        helper(root->left,ans,map); 
        helper(root->right,ans,map);
        if (!root->left && !root->right) { 
             int odd_cnt = 0;
             for (int i = 1; i <= 9; i++) {  
                if (map[i] && map[i] % 2) {
                    odd_cnt++;
                }
              }
             if (odd_cnt <= 1) ans++;  
        }        
        map[root->val]--;   
    }
public:
    int pseudoPalindromicPaths (TreeNode *root) {
        int ans = 0, map[10]{0};
        helper(root, ans, map);
        return ans;    
    }
};
