class Solution {
public:
    int dp[101];
    int f(int i,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans=0;
        ans=max(nums[i]+f(i+2,nums),f(i+1,nums));
        return dp[i]=ans;
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};