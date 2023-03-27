class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};