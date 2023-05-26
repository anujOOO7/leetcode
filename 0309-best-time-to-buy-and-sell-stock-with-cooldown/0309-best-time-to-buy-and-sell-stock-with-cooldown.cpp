class Solution {
public:
    vector<int> p;
    int dp[5001][2];
    int f(int i,int j){
        if(i>=p.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(!j) return dp[i][j]=max(-p[i]+f(i+1,1),f(i+1,0));
        return dp[i][j]=max(p[i]+f(i+2,0),f(i+1,1));
    }
    int maxProfit(vector<int>& prices) {
        p=prices;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};