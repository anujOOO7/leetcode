class Solution {
public:
    int m,n;
    vector<vector<int>> vis;
    vector<int> dx{-1,0,0,1};
    vector<int> dy{0,-1,1,0};
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0) return;
        vis[i][j]=1;
        
        for(int p=0;p<4;p++){
            int ni=i+dx[p],nj=j+dy[p];
            dfs(ni,nj,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};