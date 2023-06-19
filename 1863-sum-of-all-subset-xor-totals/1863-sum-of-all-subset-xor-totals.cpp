class Solution {
public:
    vector<int> ans;
    int f(int i,int res,vector<int>& nums){
        if(i==nums.size()) return res;
        
        return f(i+1,res,nums)+f(i+1,res^nums[i],nums);
    }
    int subsetXORSum(vector<int>& nums) {
        return f(0,0,nums);
    }
};