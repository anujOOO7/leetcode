//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int m,n,bi,bj;
  vector<int> dx{1,0,-1,0};
  vector<int> dy{0,-1,0,1};
  vector<vector<int>> vis;
  vector<pair<int,int>> ans;
  void dfs(int i,int j,vector<vector<int>>& grid){
      if(i<0 || i>=m || j<0 || j>=n || !grid[i][j] || vis[i][j]) return;
      vis[i][j]=1;
      ans.push_back({i-bi,j-bj});
      
      for(int p=0;p<4;p++){
          int ni=i+dx[p],nj=j+dy[p];
          dfs(ni,nj,grid);
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>> s;
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    bi=i,bj=j;
                    dfs(i,j,grid);
                    s.insert(ans);
                    ans.clear();
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends