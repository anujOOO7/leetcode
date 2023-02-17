class Solution {
public:
    #define mod 1000000007
    
    long long power(long long x,long long n){
        if(n==0)
            return 1;
        
        long long ans=power(x,n/2)%mod;
        
        if(n&1)
            return (x%mod * ans%mod *ans%mod)%mod;
        return (ans%mod * ans%mod)%mod;
    }
    
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2,odd=n/2;
        return (power(4,odd)%mod * power(5,even)%mod) % mod;
    }
};