//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> moves{{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
    int Count(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        int cnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]) q.push({i,j});
                else cnt++;
            }
        }
        if(cnt<=1) return 0;
        
        int ans=0;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int cnt=0;
            for(int k=0;k<8;k++)
            {
                int nr=r+moves[k][0];
                int nc=c+moves[k][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && nums[nr][nc]==0) cnt++;
            }
            if(cnt>0 && cnt%2==0) ans++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends