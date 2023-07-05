class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0,ans=INT_MAX;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>target){
                sum-=nums[l];
                ans=min(ans,r-l+1);
                l++;
            }
            if(sum>=target) ans=min(ans,r-l+1);
            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};