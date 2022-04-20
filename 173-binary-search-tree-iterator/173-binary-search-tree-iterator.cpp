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



// class BSTIterator {
//     stack<TreeNode *> myStack;
// public:
//     BSTIterator(TreeNode *root) {
//         pushAll(root);
//     }

//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         return !myStack.empty();
//     }

//     /** @return the next smallest number */
//     int next() {
//         TreeNode *tmpNode = myStack.top();
//         myStack.pop();
//         pushAll(tmpNode->right);
//         return tmpNode->val;
//     }

// private:
//     void pushAll(TreeNode *node) {
//         for (; node != NULL; myStack.push(node), node = node->left);
//     }
// };




class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->val;
    }
    
    /** put all the left child() of root */
    void find_left(TreeNode* root) {
        TreeNode* p = root;
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
    }
};




/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */