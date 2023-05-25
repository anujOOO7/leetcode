class Solution {
public:
    int n,m;
    string s,t;
    int dp[1001][1001];
    int f(int i,int j){
        if(j==0) return 1;
        if(i==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=f(i-1,j-1)+f(i-1,j);
        else return dp[i][j]=f(i-1,j);
    }
    int numDistinct(string str1, string str2) {
        s=str1,t=str2;
        n=s.size(),m=t.size();
        memset(dp,-1,sizeof(dp));
        return f(n,m);
    }
};