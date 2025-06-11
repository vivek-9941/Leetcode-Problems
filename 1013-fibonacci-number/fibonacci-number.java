class Solution {
    int fib1(int n ,int [] dp ){
         if(n <= 1)return n;
        if(dp[n]!= -1){
            return dp[n];
        }
        return dp[n] = fib1(n-1, dp) + fib1(n-2,dp);
    }
    public int fib(int n) {
       int [] dp = new int[n+1];
       for(int i =0 ;  i<= n ; i++)dp[i] = -1;
       if(n<= 1)return n;
        fib1(n, dp);
        return dp[n];
     }
}