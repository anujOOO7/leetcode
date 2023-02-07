class Solution {
public:
    typedef long long ll;
    
    bool check(ll m,ll x){
        if(m*m<=x)
            return true;
        return false;
    }
    
	int mySqrt(int x) {
		int l(0),r(x);
        if(r-l<=1)
            return x;
        
		while(r-l>1){
			ll m=(l+r)/2;
            
			if(check(m,x)){
                l=m;
            }
            else{
                r=m;
            }
		}
		return l;
	}
};