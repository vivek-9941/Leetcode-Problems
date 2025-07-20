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
    void inorder(bool& valid ,TreeNode* root, long long& prev){
        if(!root || !valid)return ;
        inorder(valid , root -> left,  prev);
        if(root -> val <= prev ){
            valid = false;
            return;
        }
        prev = root -> val;
        inorder(valid,root -> right,prev);
    }

public:
    bool isValidBST(TreeNode* root) {
        bool valid = 1;
        long long prev = LLONG_MIN;

        inorder(valid , root , prev);
        return valid;

    }
};