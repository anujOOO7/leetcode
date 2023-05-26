class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> next(2,0),cur(2,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(!j) profit=max(-prices[i]+next[1],next[0]);
                else profit=max(prices[i]+next[0],next[1]);
                cur[j]=profit;
            }
            next=cur;
        }
        return cur[0];
    }
};