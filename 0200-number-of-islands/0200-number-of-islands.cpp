class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[i][j]=1;
 
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(abs(di)+abs(dj)!=2){
                    int ni=i+di,nj=j+dj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1' && !vis[ni][nj]) dfs(ni,nj,vis,grid);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};