class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> v(n);
        v[n-1]=prices[n-1];
        int prev=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prev>prices[i])
                v[i]=prev;
            else{
                v[i]=prices[i];
                prev=prices[i];
            }
        }
        
        for(int i=0;i<n;i++){
            v[i]=v[i]-prices[i];
        }
        return *max_element(v.begin(),v.end());
    }
};