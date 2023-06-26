class Solution {
public:
    int m,n;
    int dp[201][201];
    vector<vector<int>> vis;
    int dfs(int i,int j,int prev,vector<vector<int>>& matrix){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]<=prev || vis[i][j]) return 0;
        
        int &d=dp[i][j];
        if(d!=-1) return d;
        vis[i][j]=1;
        int ans=max({1+dfs(i-1,j,matrix[i][j],matrix),1+dfs(i+1,j,matrix[i][j],matrix),1+dfs(i,j-1,matrix[i][j],matrix),1+dfs(i,j+1,matrix[i][j],matrix)});
        vis[i][j]=0;
        return d=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis.assign(m,vector<int>(n,0));
                ans=max(ans,dfs(i,j,-1,matrix));
            }
        }
        return ans;
    }
};