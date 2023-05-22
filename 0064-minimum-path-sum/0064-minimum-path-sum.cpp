class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1 && j==n-1) return grid[m-1][n-1];
        if(i>=m || j>=n) return 1e5;
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(f(i+1,j,grid),f(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,grid);
    }
};