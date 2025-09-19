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
    int tabulation(int m , int n ){
        vector<vector<int>> dp(m , vector<int> (n,0));
        for(int i =0 ; i < m ; i++){
            for(int j =  0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int down= 0;
                    if(i>0)up= dp[i-1][j];
                    if(j>0)down = dp[i][j-1];
                    dp[i][j] = up+ down;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        int cnt =0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(m-1,n-1 ,cnt,dp);
        return tabulation(m,n);
    }
};