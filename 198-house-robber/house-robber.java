class Solution {
    int solve(int[] nums, int ind , int[] dp) {
        if (ind < 0)
            return 0;
        int right = Integer.MIN_VALUE;
        int left = Integer.MIN_VALUE;
        if(dp[ind] != -1)return dp[ind];
            left = solve(nums, ind - 2, dp) + nums[ind];
            right = solve(nums, ind - 3 , dp) + nums[ind];
        return dp[ind]= Math.max(left, right);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int [] dp =  new int[n];
        Arrays.fill(dp,-1);
        return Math.max(solve(nums, n - 1 , dp),  solve(nums, n-2 ,dp));

    }
}