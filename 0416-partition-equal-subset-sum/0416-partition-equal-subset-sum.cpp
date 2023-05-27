class Solution {
public:
    int dp[201][20001];
    bool f(int i,int sum,int target,vector<int> &nums){
        if(sum==target) return true;
        if(i==nums.size()) return false;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=f(i+1,sum+nums[i],target,nums)||f(i+1,sum,target,nums); 
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum&1) return false;
        memset(dp,-1,sizeof(dp));
        return f(0,0,sum/2,nums);
    }
};