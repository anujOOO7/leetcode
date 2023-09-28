//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    vector<vector<int>> moves{{0,-1},{0,1},{1,0},{-1,0}};
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j,0});
                }
            }
        }

        int totalTime=0;
        while(!q.empty()){
            auto node=q.front();
            int r=node[0],c=node[1],t=node[2];
            totalTime=max(totalTime,t);
            q.pop();

            for(int i=0;i<4;i++){
                int ni=r+moves[i][0];
                int nj=c+moves[i][1];

                if(ni<0 || ni>=m || nj<0 || nj>=n || 
                    vis[ni][nj] || grid[ni][nj]==0 || grid[ni][nj]==2) continue;
                vis[ni][nj]=1;
                q.push({ni,nj,t+1});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }
        return totalTime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends