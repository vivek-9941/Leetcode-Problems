class Solution {
    pair<int,int> solve(TreeNode* root, int &cnt) {
        if (!root) return {0, 0};

        auto left  = solve(root->left, cnt);
        auto right = solve(root->right, cnt);

        int totalsum  = left.first + right.first + root->val;
        int totalcnt  = left.second + right.second + 1;

        int avg = totalsum / totalcnt; 
        if (avg == root->val) {
            cnt++;
        }

        return {totalsum, totalcnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};
