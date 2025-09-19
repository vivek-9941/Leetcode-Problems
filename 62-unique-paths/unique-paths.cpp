class Solution {
public:
    int solve(int i, int j , int &cnt,vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int left =0,right= 0;
        if(j >0)left = solve(i, j-1  ,cnt,dp);
        if(i >0)right = solve(i-1 , j , cnt,dp);
        return dp[i][j] = left + right;
    }
    int uniquePaths(int m, int n) {
        int cnt =0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1 ,cnt,dp);
    }
};