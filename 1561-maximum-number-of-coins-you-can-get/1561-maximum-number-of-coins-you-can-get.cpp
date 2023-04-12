class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int i=0,j=piles.size()-1,ans=0;
        while(i+1<j)
        {
            ans+=piles[i+1];
            i+=2;
            j--;
        }
        return ans;
    }
};