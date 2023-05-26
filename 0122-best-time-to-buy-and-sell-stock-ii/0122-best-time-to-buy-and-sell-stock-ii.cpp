class Solution {
public:
    vector<int> p;
    int dp[30001][2];
    int f(int i,int have_stock){
        if(i==p.size()) return 0;
        
        if(dp[i][have_stock]!=-1) return dp[i][have_stock];
        if(!have_stock) dp[i][have_stock]=max(-p[i]+f(i+1,1),f(i+1,0));
        else dp[i][have_stock]=max(p[i]+f(i+1,0),f(i+1,1));
        return dp[i][have_stock];
    }
    int maxProfit(vector<int>& prices) {
        p=prices;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};