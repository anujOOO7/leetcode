class Solution {
public:
    int dp[101][101];
    int f(int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        
        int &d=dp[i][j];
        if(d!=-1) return d;
        return d=f(i+1,j,m,n)+f(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,m,n);       
    }
};