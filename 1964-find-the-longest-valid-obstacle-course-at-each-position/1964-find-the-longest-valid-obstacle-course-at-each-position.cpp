class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> ans,temp;
        ans.push_back(1);
        temp.push_back(nums[0]);
        for(int i=1;i<size(nums);i++){
            auto ind=upper_bound(begin(temp),end(temp),nums[i])-begin(temp);
            if(ind>=temp.size()) temp.push_back(nums[i]);
            else temp[ind]=nums[i];
            ans.push_back(ind+1);
        }
        return ans;
    }
};