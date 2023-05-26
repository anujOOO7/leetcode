class Solution {
public:
    int maxProfit(int t, vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2][t+1];
        for(int i=n;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=t;k++){
                    if(i==n || k==0) dp[i][j][k]=0;
                    else{
                        if(k){
                            if(!j) dp[i][j][k]=max(-prices[i]+dp[i+1][1][k],dp[i+1][0][k]);
                            else dp[i][j][k]=max(prices[i]+dp[i+1][0][k-1],dp[i+1][1][k]);
                        }
                    }
                }
            }
        }
        return dp[0][0][t];
    }
};