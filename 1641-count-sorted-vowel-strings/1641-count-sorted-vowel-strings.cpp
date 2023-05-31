class Solution {
public:
    int dp[51][51];
    int f(int i, int n){
        if(n==0) return 1;
        if(i>=5) return 0;

        if(dp[i][n]!=-1) return dp[i][n];
        return dp[i][n]=f(i,n-1)+f(i+1,n);
    }

    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,n);
    }
};