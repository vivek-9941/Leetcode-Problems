/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool solve(set<int>& st, TreeNode* root, int& k) {
        if (!root)
            return false;
        if (st.contains(k - (root->val)))
            return true;
        st.insert(root->val);

        return solve(st, root->left, k) || solve(st, root->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return solve(st, root, k);
    }
};