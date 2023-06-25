class Solution {
public:
    int f(int i,int len,vector<int>& nums,vector<int>& dp){
        if(i>=len) return 0;
        
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(f(i+1,len,nums,dp),nums[i]+f(i+2,len,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1,-1),dp2(n+1,-1);
        return max(f(0,n-1,nums,dp1),f(1,n,nums,dp2));
    }
};