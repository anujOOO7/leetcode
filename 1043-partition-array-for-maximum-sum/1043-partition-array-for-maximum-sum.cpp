class Solution {
public:
    int n,k;
    int dp[501];
    int f(int i,vector<int> &nums){
        if(i==n) return 0;
        
        int &d=dp[i];
        if(d!=-1) return d;
        int ans=0,mx=0;
        for(int j=i;j<min(n,i+k);j++){
            mx=max(mx,nums[j]);
            ans=max(ans,mx*(j-i+1)+f(j+1,nums));
        }
        return d=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int sz) {
        n=arr.size(),k=sz;
        memset(dp,-1,sizeof(dp));
        return f(0,arr);
    }
};