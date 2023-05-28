class Solution {
public:
    int n;
    int dp[201][201];
    vector<vector<int>> t;
    int f(int i,int j){
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=t[i][j]+min(f(i+1,j),f(i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        t=triangle,n=t.size();
        return f(0,0);
    }
};