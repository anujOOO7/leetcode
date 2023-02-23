class Solution {
public:
    vector<vector<int>> ans;
    
    void gen(vector<int> &nums,vector<int> &v,int i){
        if(v.size()==nums.size() || i==nums.size()){
            ans.push_back(v);
            return;
        }
        
        gen(nums,v,i+1);
        v.push_back(nums[i]);
        gen(nums,v,i+1);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        gen(nums,v,0);
        return ans;
    }
};