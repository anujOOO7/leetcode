class Solution {
public:
    long long dp[100001];
    long long f(int i,vector<vector<int>>& q){
        if(i>=q.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        ans=max(q[i][0]+f(i+q[i][1]+1,q),f(i+1,q));
        return dp[i]=ans;
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        memset(dp,-1,sizeof(dp));
        return f(0,q);
    }
};