class Solution {
public:
    using ll=long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll> (2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(!j) dp[i][j]=max(nums[i]+dp[i+1][1],dp[i+1][0]);
                else dp[i][j]=max(-nums[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        return dp[0][0];
    }
};