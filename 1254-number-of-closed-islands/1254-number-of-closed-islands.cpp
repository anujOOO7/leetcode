class Solution {
public:
    int m,n;
    vector<vector<int>> vis;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] || vis[i][j]) return;
        
        vis[i][j]=1;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m=size(grid),n=size(grid[0]);
        vis.assign(m,vector<int>(n,0));
        
        //marking all non-isalnds as visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && !grid[i][j] && !vis[i][j]){
                    dfs(i,j,grid);
                }
            }
        }
        
        //counting the islands
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j] && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid);
                }
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
        }
        return cnt;
    }
};