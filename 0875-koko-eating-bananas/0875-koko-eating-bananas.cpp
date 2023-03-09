class Solution {
public:
    typedef long long ll;
    bool check(vector<int>& piles,ll mid,int h){
        ll time=0;
        for(auto p:piles){
            time+=(p+mid-1)/mid;
        }
        return time<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {        
        ll l=0,r=1e18;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(check(piles,mid,h))
                r=mid;
            else
                l=mid;
        }
        return r;
    }
};