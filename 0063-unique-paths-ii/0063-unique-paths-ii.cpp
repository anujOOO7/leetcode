class Solution {
public:
    int dp[101][101];
    int f(int i,int j,vector<vector<int>> &g){
        int m=g.size(),n=g[0].size();
        if(g[m-1][n-1]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(g[i][j]==1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=f(i+1,j,g)+f(i,j+1,g);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,g);
    }
};