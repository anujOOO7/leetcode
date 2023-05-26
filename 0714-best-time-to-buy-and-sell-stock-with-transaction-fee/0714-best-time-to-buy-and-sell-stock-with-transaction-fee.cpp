class Solution {
public:
    int charge;
    vector<int> p;
    int dp[50001][2];
    int f(int i,int j){
        if(i>=p.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(!j) return dp[i][j]=max(-p[i]+f(i+1,1),f(i+1,0));
        else return dp[i][j]=max(-charge+p[i]+f(i+1,0),f(i+1,1));
    }
    int maxProfit(vector<int>& prices, int fee) {
        p=prices,charge=fee;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};