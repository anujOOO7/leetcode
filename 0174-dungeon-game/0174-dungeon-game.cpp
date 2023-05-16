class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>& d){
        int m=d.size(),n=d[0].size();
        if(i==m-1 && j==n-1) return d[i][j]>0?1:1-d[i][j];
        if(i>=m || j>=n) return 1e5;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e5;
        ans=min(f(i+1,j,d),f(i,j+1,d))-d[i][j];
        return dp[i][j]=ans>0?ans:1;
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,d);
    }
};