class Solution {
public:
    int m,n;
    bool dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        if(i<0 ||i>=m || j<0 || j>=n || grid2[i][j]!=1) return true;
        if(grid1[i][j]==0) return false;
        grid2[i][j]=-1;
        bool ans=true;
        ans&=dfs(i+1,j,grid1,grid2);
        ans&=dfs(i-1,j,grid1,grid2);
        ans&=dfs(i,j-1,grid1,grid2);
        ans&=dfs(i,j+1,grid1,grid2);
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid2.size(),n=grid2[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2)) cnt++;
                }
            }
        }
        return cnt;
    }
};