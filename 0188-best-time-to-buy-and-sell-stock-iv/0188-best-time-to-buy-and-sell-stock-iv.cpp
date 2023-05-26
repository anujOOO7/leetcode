class Solution {
public:
    int maxProfit(int t, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int> (t+1,0)),cur(2,vector<int> (t+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=t;k++){
                    if(k){
                        if(!j) cur[j][k]=max(-prices[i]+next[1][k],next[0][k]);
                        else cur[j][k]=max(prices[i]+next[0][k-1],next[1][k]);
                    }
                }
            }
            next=cur;
        }
        return cur[0][t];
    }
};