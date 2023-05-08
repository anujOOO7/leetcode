class Solution {
public:
    int dp[201][201];
    
    int f(int i,int j,vector<vector<int>>& g){
        int m=g.size(),n=g[0].size();
        if(i>=m || j>=n) return INT_MAX-1;
        if(i==m-1 && j==n-1) return g[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=g[i][j]+min(f(i,j+1,g),f(i+1,j,g));
    }
    int minPathSum(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,g);
    }
};