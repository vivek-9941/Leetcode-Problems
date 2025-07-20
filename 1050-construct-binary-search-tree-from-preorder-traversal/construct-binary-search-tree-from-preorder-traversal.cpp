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
    TreeNode* construct(vector<int>& preorder, int index , TreeNode* root){
            if(!root){
                TreeNode* newnode = new TreeNode(preorder[index++]);
                return newnode;
            }
            if(root -> val  < preorder[index]){
                root -> right = construct(preorder, index, root-> right);
            }
            else{
            root -> left = construct(preorder, index, root-> left);
   
            }
            return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i  = 1 ; i < preorder.size(); i++){

        construct(preorder , i , root);
        }
        return root;
    }
};