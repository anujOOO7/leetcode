class Solution {
public:
    int dp[101][101];
    
    int f(int i,int j,vector<vector<int>>& m){
        int n=m.size();
        if(i>=n) return 0;
        if(j<0 || j+1>n) return 1e5;
        if(i==n-1) return m[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        ans=min(ans,m[i][j]+f(i+1,j-1,m));
        ans=min(ans,m[i][j]+f(i+1,j,m));
        ans=min(ans,m[i][j]+f(i+1,j+1,m));
        
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& m) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int j=0;j<m.size();j++){
            ans=min(ans,f(0,j,m));
        }
        return ans;
    }
};