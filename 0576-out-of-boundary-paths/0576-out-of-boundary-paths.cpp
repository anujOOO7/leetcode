class Solution {
public:
    int m,n;
    using ll=long long;
    const int mod=1000000007;
    ll dp[60][60][60];
    ll f(int i,int j,int cnt){
        if(cnt<0) return 0;
        if((i<0 || j<0 || i>=m || j>=n) && cnt>=0) return 1;
        
        ll &d=dp[i+5][j+5][cnt+5];
        if(d!=-1) return d;
        ll ans=(f(i-1,j,cnt-1)%mod+f(i+1,j,cnt-1)%mod+f(i,j-1,cnt-1)%mod+f(i,j+1,cnt-1)%mod)%mod;
        ans%=mod;
        return d=ans;
    }
    int findPaths(int M, int N, int maxMove, int startRow, int startColumn) {
        m=M,n=N;
        memset(dp,-1,sizeof(dp));
        return f(startRow,startColumn,maxMove);
    }
};