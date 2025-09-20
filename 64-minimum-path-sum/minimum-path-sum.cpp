class Solution {
    int solve(int i , int j ,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == 0 && j ==0 ){
            return grid[i][j];
        }
        if( i< 0 || j < 0)return INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        int left =0, right =0;
       left = solve(i-1, j ,grid,dp);
        right =solve(i, j -1,grid,dp);
        
        return dp[i][j] =grid[i][j]  + min(left, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi =INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};