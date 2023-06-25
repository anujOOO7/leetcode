class Solution {
public:
    int dp[21][2002];
    int f(int i,int sum,int t,vector<int>& nums){
        if(i==nums.size()){
            if(sum==t) return 1;
            else return 0;
        }
        
        int &d=dp[i][sum+1000];
        if(d!=-1) return d;
        return d=f(i+1,sum-nums[i],t,nums)+f(i+1,sum+nums[i],t,nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,target,nums);
    }
};