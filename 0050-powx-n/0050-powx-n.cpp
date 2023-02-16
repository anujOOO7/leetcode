class Solution {
public:
    
    double posPow(double x, int k){
        if(k==0)
            return 1;
        double ans=posPow(x,k/2);
        
        if(k&1)
            return x*ans*ans;
        return ans*ans;
    }
    
    double negPow(double x, int k){
        if(k==0)
            return 1;
        double ans=posPow(x,k/2);
        
        if(k&1)
            return 1/(x*ans*ans);
        return 1/(ans*ans);
    }
    
    double myPow(double x, int k) {
        if(k>=0)
            return posPow(x,k);
        return negPow(x,abs(k));
    }
};