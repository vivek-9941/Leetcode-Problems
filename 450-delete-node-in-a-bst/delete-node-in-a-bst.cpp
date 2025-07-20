class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            return helper(root);
        } 
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findRightMost(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findRightMost(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }
};
