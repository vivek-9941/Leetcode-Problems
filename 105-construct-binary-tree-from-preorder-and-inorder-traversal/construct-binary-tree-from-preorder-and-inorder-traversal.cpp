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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int end, int start, int&preindex , unordered_map<int,int>& mpp){
        if(start > end || preindex  == preorder.size())return nullptr;
        int element = preorder[preindex++];
        int pos = mpp[element];
        TreeNode* node = new TreeNode(element);
        node -> left  = solve(preorder, inorder , pos-1,start , preindex , mpp);  
        node -> right = solve(preorder, inorder ,end, pos +1  , preindex , mpp);
        return node;
          }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        int inorderend = n-1;
        int inorderstart = 0;
        int preindex= 0;
        unordered_map<int,int> mpp;
        for(int i  =0 ;  i < n ; i++){
            mpp[inorder[i]] = i;
        }
        return solve(preorder, inorder , inorderend, inorderstart , preindex , mpp);

    }
};