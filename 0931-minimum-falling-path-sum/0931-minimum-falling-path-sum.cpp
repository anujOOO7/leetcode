class Solution {
public:
    int dp[101][101];
    
    int f(int i,int j,vector<vector<int>>& m){
        if(j>=m[0].size() || j<0)
            return 1e5;
        if(i==m.size()-1)
            return m[i][j];
        if(i>=m.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        ans=min(ans,m[i][j]+f(i+1,j-1,m));
        ans=min(ans,m[i][j]+f(i+1,j,m));
        ans=min(ans,m[i][j]+f(i+1,j+1,m));
        
      return dp[i][j]=ans;
        
    
        
    }
    int minFallingPathSum(vector<vector<int>>& m) {
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<m[0].size();i++)
        {
            ans=min(ans,f(0,i,m));
        }
        return ans;
    }
};