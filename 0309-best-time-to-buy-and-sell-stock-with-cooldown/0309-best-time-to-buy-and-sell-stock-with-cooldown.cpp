class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> cur(2,0),next(2,0),n2n(2,0);
        
        for(int i=n-1;i>=0;i--){
            cur[0]=max(-prices[i]+next[1],next[0]);
            cur[1]=max(prices[i]+n2n[0],next[1]);
            n2n=next,next=cur;
        }
        return cur[0];
    }
};