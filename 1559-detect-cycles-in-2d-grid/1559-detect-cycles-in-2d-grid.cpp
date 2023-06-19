class Solution {
public:
    int m,n;
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,-1};
    vector<vector<int>> vis;
    vector<vector<char>> grid;
    
    bool dfs(int row,int col,int px,int py,char c){
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int ni=row+dx[i],nj=col+dy[i];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==c){
                if(!vis[ni][nj]){
                    if(dfs(ni,nj,row,col,c)) return true;
                }
                else{
                    if(ni!=px && nj!=py) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& g) {
        grid=g;
        m=g.size(),n=g[0].size();
        vis.resize(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};