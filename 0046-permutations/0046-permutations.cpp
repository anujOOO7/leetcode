class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(vector<int>& nums,vector<int> v,int i){
        //base case
        if(i==nums.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(v[i],v[j]);
            permute(nums,v,i+1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp=nums;
        permute(nums,temp,0);
        return ans;
    }
};