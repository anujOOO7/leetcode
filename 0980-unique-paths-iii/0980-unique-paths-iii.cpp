class Solution {
public:
    int m,n,cnt=0;
    vector<vector<int>> vis;
    int f(int i,int j,int c,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1 || vis[i][j]) return 0;
        if(grid[i][j]==2) return c==cnt?1:0;
        
        vis[i][j]=1;
        int count=f(i-1,j,c+1,grid)+f(i+1,j,c+1,grid)+f(i,j-1,c+1,grid)+f(i,j+1,c+1,grid);
        vis[i][j]=0;
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        int si,sj;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) si=i,sj=j;
                if(grid[i][j]!=-1) cnt++;
            }
        }
        return f(si,sj,1,grid);
    }
};