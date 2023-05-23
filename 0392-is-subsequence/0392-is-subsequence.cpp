class Solution {
public:
    int n,m;
    int dp[101][10001];
    int f(int i,int j,string s,string t){
        if(i==n || j==m) return 0;
            
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=1+f(i+1,j+1,s,t);
        return dp[i][j]=f(i,j+1,s,t);
    }
    bool isSubsequence(string s, string t) {
        n=s.length(),m=t.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,t)==s.size()?1:0;
    }
};