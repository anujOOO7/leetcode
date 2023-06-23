class Solution {
public:
    int n,m;
    vector<vector<int>> vis;
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || !grid[i][j] || vis[i][j]) return 0;
        vis[i][j]=1;
        return 1+dfs(i+1,j,grid)+dfs(i-1,j,grid)+dfs(i,j+1,grid)+dfs(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        
        //checking for max area of islands
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};