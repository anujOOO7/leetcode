class Solution {
public:
    vector<int> p;
    int dp[1001][2][101];
    int f(int i,int j,int count){
        if(i==p.size() || count==0) return 0;
        
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        if(count){
            if(!j) dp[i][j][count]=max(-p[i]+f(i+1,1,count),f(i+1,0,count));
            else dp[i][j][count]=max(p[i]+f(i+1,0,count-1),f(i+1,1,count));
        }
        return dp[i][j][count];
    }
    int maxProfit(int k, vector<int>& prices) {
        p=prices;
        memset(dp,-1,sizeof(dp));
        return f(0,0,k);
    }
};