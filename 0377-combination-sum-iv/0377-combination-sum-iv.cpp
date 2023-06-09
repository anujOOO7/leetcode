class Solution {
public:
    int dp[1001];
    vector<int> nums;
    int f(int target){
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int i=0;i<size(nums);i++){
            if(nums[i]<=target){
                ans+=f(target-nums[i]);
            }
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& arr, int target) {
        nums=arr;
        memset(dp,-1,sizeof(dp));
        return f(target);
    }
};