class Solution {
public:
    int dp[60];
    int f(int n){
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1;i<=n;i++){
            ans=max(ans,i*f(n-i));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        if(n<4) return n-1;
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};