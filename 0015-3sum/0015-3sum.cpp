class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};