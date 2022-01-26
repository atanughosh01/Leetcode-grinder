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
// TC : O(NlogN), SC : O(N)
class Solution {
public:
     vector<int> res;
     void dfs(TreeNode *root) {
          if (!root)
               return;
          res.emplace_back(root->val);
          dfs(root->left);
          dfs(root->right);
     }
     vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
          dfs(root1);
          dfs(root2);
          sort(res.begin(), res.end());
          return res;
     }
};
*/

// TC : O(N), SC : O(N)
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &v){
        if (!root)
               return;
        dfs(root->left,v);
        v.emplace_back(root->val);
        dfs(root->right,v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        dfs(root1,a);
        dfs(root2,b);
        
        vector<int> ans((int)(a.size()+b.size()));
        int i=0,j=0,k=0;

        while(i<(int)a.size() and j<(int)b.size())
            ans[k++]=a[i]<b[j] ? a[i++] : b[j++];

        while(i<(int)a.size())
            ans[k++]=a[i++];

        while(j<(int)b.size())
            ans[k++]=b[j++];

        return ans;
    }
};
