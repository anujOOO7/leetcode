class Solution {
public:
    int n,mn;
    const int mod=1e9+7;
    using ll=long long;
    ll dp[101][101][201];
    vector<int> group,profit;
    ll f(int i,int m,int pr){
        if(i==profit.size()){
            if(m<=n && pr>=mn) return 1;
            return 0;
        }
        if(m>n) return 0;
        
        int k=min(pr,mn);
        ll &d=dp[i][m][k];
        if(d!=-1) return d;
        ll ans=0;
        ans+=f(i+1,m+group[i],pr+profit[i])%mod;
        ans+=f(i+1,m,pr)%mod;
        return d=ans%mod;
    }
    int profitableSchemes(int N, int minProfit, vector<int>& g, vector<int>& p) {
        n=N,profit=p,group=g,mn=minProfit;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0);
    }
};