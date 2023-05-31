class Solution {
public:
    string s1,s2;
    vector<vector<int>> dp;
    bool f(int i,int j){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++) if(s2[k]!='*') return false;
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j] || s2[j]=='?') return dp[i][j]=f(i-1,j-1);
        if(s2[j]=='*') return dp[i][j]=f(i,j-1) || f(i-1,j);
        return false;
    }
    bool isMatch(string s, string p) {
        s1=s,s2=p;
        int n=s.length(),m=p.length();
        dp.resize(n+1,vector<int> (m+1,-1));
        return f(n-1,m-1);
    }
};