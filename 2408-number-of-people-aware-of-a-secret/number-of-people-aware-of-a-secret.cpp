class Solution {
public:
  const int mod=1e9+7;
  int helper(int day,int n,int d,int f,vector<int>&dp){
    if(day==n){
        return 1;
    }
    if(day>n) return 0;
    if(dp[day]!=-1){
        return dp[day];
    }
 int  ans=1;
    for(int i=day+d;i<=min(day+f,n);i++){
        if(i==day+f){
            ans--;
            break;
        }
        ans=(ans+(helper(i,n,d,f,dp)))%mod;
    }
    return dp[day]=ans;

  }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,-1);
        return helper(1,n,delay,forget,dp);
        
    }
};