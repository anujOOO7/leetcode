class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size(),k=piles.size()/3,ans=0;
        for(int i=0;i<n;i+=2)
        {
            ans+=piles[i+1];
            --k;
            if(k==0) break;
        }
        return ans;
    }
};