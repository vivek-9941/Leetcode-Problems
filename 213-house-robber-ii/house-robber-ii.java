class Solution {
    int solve(int[] nums, int ind, int[] dp, int end) {
        if (ind < end) return 0;

        if (dp[ind] != -1) return dp[ind];

        int take1 = solve(nums, ind - 2, dp, end) + nums[ind];
        int take2 = solve(nums, ind - 3, dp, end) + nums[ind];

        return dp[ind] = Math.max(take1, take2);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from 0 to n-2 (exclude last house)
        int[] dp1 = new int[n];
        Arrays.fill(dp1, -1);
        int case1 = Math.max(
            solve(nums, n - 2, dp1, 0),
            solve(nums, n - 3, dp1, 0)
        );

        // Case 2: Rob from 1 to n-1 (exclude first house)
        int[] dp2 = new int[n];
        Arrays.fill(dp2, -1);
        int case2 = Math.max(
            solve(nums, n - 1, dp2, 1),
            solve(nums, n - 2, dp2, 1)
        );

        return Math.max(case1, case2);
    }
}
