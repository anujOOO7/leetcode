class Solution {
public:
    int n,m;
    string s1,s2;
    int dp[501][501];
    int f(int i,int j){
        if(i==n || j==m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+f(i+1,j+1);
        return dp[i][j]=max(f(i+1,j),f(i,j+1));
    }
    int minDistance(string word1, string word2) {
        s1=word1,s2=word2;
        n=s1.length(),m=s2.length();
        memset(dp,-1,sizeof(dp));
        return n+m-2*f(0,0);
    }
};