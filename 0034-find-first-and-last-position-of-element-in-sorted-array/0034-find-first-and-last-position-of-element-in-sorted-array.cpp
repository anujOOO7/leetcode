class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        if(nums.size()==0)
            return ans;
        
        if(lower_bound(nums.begin(),nums.end(),target)!=nums.end() && nums[lower_bound(nums.begin(),nums.end(),target)-nums.begin()]==target){
            ans[0]=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            for(int i=ans[0];i<nums.size();i++){
                if(nums[i]==target)
                    ans[1]=i;
            }
        }
        else
            return {-1,-1};
        return ans;
    }
};