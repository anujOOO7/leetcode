class Solution {
public:
    int dp[1001][1001];
    int f(int count,int copied,int n){
        if(count>n || copied>n) return 1e6;
        if(count==n) return 1;
        
        int &d=dp[count][copied];
        if(d!=-1) return d;
        return d=min({1+f(count+copied,copied,n),2+f(2*count,count,n)});
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
        return f(1,1,n);
    }
};