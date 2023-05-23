class Solution {
public:
    string s;
    int dp[501][501];
    int f(int l,int r){
        if(l>r) return 0;
        if(l==r) return 1;
        
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return dp[l][r]=2+f(l+1,r-1);
        return dp[l][r]=max(f(l+1,r),f(l,r-1));
    }
    int minInsertions(string S) {
        s=S;
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return n-f(0,n-1);
    }
};