class Solution {
public:
    int m,n;
    vector<vector<int>> a,b;
    vector<vector<int>> vis;
    void dfs(int i,int j,bool &flag){
        if(i<0 ||i>=m || j<0 || j>=n || !b[i][j] || vis[i][j]) return;
        flag&=(a[i][j]==b[i][j]);
        vis[i][j]=1;
        dfs(i+1,j,flag);
        dfs(i-1,j,flag);
        dfs(i,j-1,flag);
        dfs(i,j+1,flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        a=grid1,b=grid2;
        m=grid2.size(),n=grid2[0].size();
        vis.resize(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    bool flag=true;
                    dfs(i,j,flag);
                    cnt+=flag;
                }
            }
        }
        return cnt;
    }
};