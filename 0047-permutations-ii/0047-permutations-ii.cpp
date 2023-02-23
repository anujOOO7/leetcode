class Solution {
public:
    set<vector<int>> ans;
    
    void permute(vector<int>& nums,vector<int> v,int i){
        //base case
        if(i==nums.size()){
            ans.insert(v);
            return ;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(v[i],v[j]);
            permute(nums,v,i+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp=nums,num=nums;
        vector<vector<int>> v;
        sort(num.begin(),num.end());
        permute(num,temp,0);
        
        for(auto val:ans){
            v.push_back(val);
        }
        return v;
    }
};