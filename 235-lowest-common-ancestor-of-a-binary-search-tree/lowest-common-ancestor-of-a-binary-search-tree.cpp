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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root )return nullptr;
        if(p == root)return p;
        if(q  == root)return q;
        TreeNode* left = lca(root -> left , p,q);
        TreeNode* right = lca(root -> right , p, q);
        if(!left && !right)return nullptr;
        else if(!left)return right;
        else if(!right)return left;
        else return root;


    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root  , p , q);
    }
};