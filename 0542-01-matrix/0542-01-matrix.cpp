class Solution {
public:
    vector<vector<int>> vis,dist;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vis.resize(m,vector<int>(n,0));
        dist.resize(m,vector<int>(n,0));
        queue<vector<int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty()){
            int x=q.front()[0],y=q.front()[1],d=q.front()[2];
            q.pop();
            dist[x][y]=d;
            
            vector<int> dx{-1,0,0,1};
            vector<int> dy{0,-1,1,0};
            
            for(int i=0;i<4;i++){
                int ni=x+dx[i],nj=y+dy[i];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj]){
                    vis[ni][nj]=1;
                    q.push({ni,nj,d+1});
                }
            }
        }
        return dist;
    }
};