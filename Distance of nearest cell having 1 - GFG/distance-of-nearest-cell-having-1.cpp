//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int m,n;
    vector<vector<int>> vis,dist;
    queue<vector<int>> q;
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    m=grid.size(),n=grid[0].size();
	    vis.resize(m,vector<int>(n,0));
	    dist.resize(m,vector<int>(n,0));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({i,j,0});
	                vis[i][j]=1;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends