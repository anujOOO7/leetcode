class Solution {
public:
    vector<vector<int>> moves{{-1,0},{1,0},{0,-1},{0,1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<vector<int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vis[i][j]=1;
                    q.push({i,j,0});
                    cnt++;
                }
            }
        }
        
        if(cnt==0 || cnt==n*n) return -1;
        int ans=-1;
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int d=q.front()[2];
            q.pop();
            
            ans=max(ans,d);
            for(auto i:moves){
                int ni=x+i[0];
                int nj=y+i[1];

                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj] && !grid[ni][nj]){
                    vis[ni][nj]=1;
                    q.push({ni,nj,d+1});
                }
            }
        }
        return ans;
    }
};