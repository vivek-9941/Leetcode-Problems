class Solution {
    bool solve(int target ,vector<int> & arr , int i,vector<vector<int>>& dp){
        if( i== 0)return target == arr[0];
        if(target == 0)return true;
        bool take =false ;
        if(dp[i][target] != -1)return dp[i][target];
        if(arr[i] <= target ){
           take = solve(target - arr[i] , arr, i-1,dp);

        }
        bool nottake = solve(target , arr, i-1,dp);
        return dp[i][target] =take | nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        long long int sum  = accumulate(nums.begin(), nums.end(),0);
        if(sum%2)return false;
        int req  = sum /2;
        vector<vector<int>> dp(nums.size() , vector<int>(req+1, -1));
     return  solve(req , nums , nums.size()-1,dp);
    }
};