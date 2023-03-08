class Solution {
public:
    vector<vector<int>> ans;
    
    void gen(int ind,vector<int> &nums,vector<int> &temp,int target){
        if(target==0){
            ans.push_back(temp);
            return ;
        }

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            if(nums[i]>target)
                break;

            temp.push_back(nums[i]);
            gen(i+1,nums,temp,target-nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int ind=0;
        gen(ind,nums,temp,target);
        return ans;
    }
};