class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>& t)
    {
        if(i==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=t[i][j]+min(f(i+1,j,t),f(i+1,j+1,t));
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,triangle);
        return ans;
    }
};