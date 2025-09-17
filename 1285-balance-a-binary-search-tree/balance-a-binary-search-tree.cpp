class Solution {
    void inorder(vector<int> &arr, TreeNode* root) {
        if(root == nullptr) return;
        inorder(arr, root->left);
        arr.push_back(root->val);
        inorder(arr, root->right);
    }

    TreeNode* create(vector<int> &arr, int l, int h) {
        if(l > h) return nullptr;
        int mid = (l+h)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = create(arr, l, mid-1);
        root->right = create(arr, mid+1, h);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(arr, root);  
        return create(arr, 0, arr.size()-1);
    }
};
