class Solution {
    int solve(int n , int m,vector<vector<int>>& arr){
        vector<vector<int>> dp(n, vector<int> (m,0));
         if (arr[0][0] == 1) return 0;
        dp[0][0] = 1;
        for(int i =0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if (i == 0 && j == 0) continue; // don't overwrite start

                if(arr[i][j] == 1){
                    dp[i][j] =0;
                }
                else {
                    int up = 0,down =0;
                    if(i>0)up = dp[i-1][j];
                    if(j > 0)down = dp[i][j-1];
                    dp[i][j] = up + down;
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int  m =arr[0].size();
        return solve(n,m,arr);
    }
};