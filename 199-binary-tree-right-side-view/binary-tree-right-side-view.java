/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    void helper(TreeNode root, Set<Integer> st, ArrayList<Integer> arr, int level) {
        if (root == null)
            return;
        if (st.contains(level)) {

        } else {
            st.add(level);
            arr.add(root.val);
        }

        helper(root.right, st, arr, level + 1);
        helper(root.left, st, arr, level + 1);

    }

    public List<Integer> rightSideView(TreeNode root) {
        Set<Integer> st = new HashSet<>();
        ArrayList<Integer> arr = new ArrayList<>();

        helper(root, st, arr, 0);
        return arr;

    }
}