class Solution {
public:
    int n,m;
    string s1,s2;
    int dp[1001][1001];
    int f(int i,int j){
        if(i==n || j==m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=s1[i]+f(i+1,j+1);
        return dp[i][j]=max(f(i+1,j),f(i,j+1));
    }
    int minimumDeleteSum(string str1, string str2) {
        s1=str1,s2=str2;
        n=s1.length(),m=s2.length();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++) ans+=s1[i];
        for(int j=0;j<m;j++) ans+=s2[j];
        return ans-2*f(0,0);
    }
};