class Solution {
public:
    const int mod=1000000007;
    using ll=long long;
    int numOfWays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n + 1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) 
        {
            dp[i][0]=1;
            for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
        function<int(vector<int>&)> dfs=[&](vector<int>& nums)
        {
            int n=nums.size();
            if(n<=2) return 1;
            vector<int> l,r;
            for(int i=1;i<n;i++) 
            {
                if (nums[i]<nums[0]) l.push_back(nums[i]);
                else r.push_back(nums[i]);
            }
            ll res=dp[n-1][l.size()];
            res=res*dfs(l)%mod;
            res=res*dfs(r)%mod;
            return (int)res;
        };
        return dfs(nums)-1;
    }
};