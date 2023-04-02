class Solution {
public:
#define ll long long
    ll getPairs(int spell, vector<int>& potions, ll success){
        ll l=0,n=potions.size(),r=n-1,ind=n;
        while(l<=r){
            ll mid=(l+r)/2;
            ll product=potions[mid]*(ll)spell;
            if(product>=success) ind=mid,r=mid-1;
            else l=mid+1;
        }
        return n-ind;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        vector<int> ans(spells.size());
        sort(begin(potions),end(potions));
        for(int i=0;i<spells.size();i++){
            ans[i]=getPairs(spells[i],potions,success);
        }
        return ans;
    }
};