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
    int preInd=0;
    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int start, int end) {
        if (start > end) return NULL; 
        TreeNode *node = new TreeNode(preorder[preInd++]);
        int pos = -1;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = createTree(preorder, inorder, start, pos - 1);
        node->right = createTree(preorder, inorder, pos + 1, end);
        return node;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return createTree(preorder, inorder, 0, inorder.size() - 1);
    }
};
