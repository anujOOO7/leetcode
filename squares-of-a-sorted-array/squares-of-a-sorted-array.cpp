class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=abs(nums[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<nums.size();i++){
            ans[i]=ans[i]*ans[i];
        }
        return ans;
    }
};