//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n,m;
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    int ni=i+di,nj=j+dj;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1' && !vis[ni][nj]){
                        bfs(ni,nj,vis,grid);
                    }
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
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends