class Solution {
public:
    int m,n;
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<tuple<int,int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j,0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int r=get<0>(q.front()),c=get<1>(q.front()),t=get<2>(q.front());
            ans=max(ans,t);
            q.pop();
            
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    int ni=r+di,nj=c+dj;
                    if(abs(di)+abs(dj)!=2 && ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1 && !vis[ni][nj]){
                        q.push({ni,nj,t+1});
                        vis[ni][nj]=1;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};