//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int m,n;
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<vector<int>> q;
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
            int r=q.front()[0],c=q.front()[1],t=q.front()[2];
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