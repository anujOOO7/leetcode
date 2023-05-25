class Solution {
public:
    int n,m;
    string s1,s2;
    int dp[501][501];
    int f(int i,int j){
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=f(i-1,j-1);
        return dp[i][j]=min(1+f(i,j-1),min(1+f(i-1,j),1+f(i-1,j-1)));
    }
    int minDistance(string word1, string word2) {
        s1=word1,s2=word2;
        n=s1.length(),m=s2.length();
        memset(dp,-1,sizeof(dp));
        return f(n-1,m-1);
    }
};