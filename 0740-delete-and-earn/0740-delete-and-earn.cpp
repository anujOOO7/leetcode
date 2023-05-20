class Solution {
public:
    int dp[20001];
    int f(int i,vector<int> &nums){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int x=lower_bound(nums.begin(),nums.end(),nums[i]+2)-nums.begin();
        ans+=max(nums[i]*m[nums[i]]+f(x,nums),f(i+1,nums));
        return dp[i]=ans;
    }
    map<int,int> m;
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        sort(begin(nums),end(nums));
        return f(0,nums);
    }
};