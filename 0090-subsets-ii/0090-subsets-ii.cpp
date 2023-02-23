class Solution {
public:
    vector<vector<int>> ans;
    
    void gen(vector<int>& nums,vector<int> v,int i){
        //base case
        if(i==nums.size()){
            sort(v.begin(),v.end());
            bool isPresent=find(ans.begin(),ans.end(),v)!=ans.end();
            if(!isPresent){
                ans.push_back(v);
            }
            return ;
        }
        
        //not take
        gen(nums,v,i+1);
        
        //take
        v.push_back(nums[i]);
        gen(nums,v,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        gen(nums,v,0);
        return ans;
    }
};