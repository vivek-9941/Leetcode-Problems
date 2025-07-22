class Solution {
    int solve(vector<int>& cost,int i,int sum,vector<int>& dp){
        if(i  >= cost.size())return 0;
        if(dp[i]!= -1)return dp[i];
        int c1 = solve(cost, i+1 , sum+ cost[i],dp);
        int c2 = solve(cost , i+2 , sum + cost[i],dp);
        return dp[i]=min(c1,c2)+cost[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(solve(cost,0,0,dp), solve(cost,1,0,dp));
    }
};