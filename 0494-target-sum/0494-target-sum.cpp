class Solution {
public:
    int f(int i,int sum,int t,vector<int>& nums){
        if(i==nums.size()){
            if(sum==t) return 1;
            else return 0;
        }
        
        return f(i+1,sum-nums[i],t,nums)+f(i+1,sum+nums[i],t,nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,0,target,nums);
    }
};