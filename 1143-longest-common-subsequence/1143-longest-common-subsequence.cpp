class Solution {
public:
    string s1,s2;
    vector<vector<int>> dp;
    int f(int x,int y){
        if(x<0 || y<0) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        if(s1[x]==s2[y]) return 1+f(x-1,y-1);
        return dp[x][y]=max(f(x-1,y),f(x,y-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int x=text1.length()-1,y=text2.length()-1;
        s1=text1,s2=text2;
        dp.resize(x+1,vector<int>(y+1,-1));
        return max(0,f(x,y));
    }
};