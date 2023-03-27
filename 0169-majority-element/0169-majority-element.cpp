class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        int mx=0,ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>mx){
                mx=i.second;
                ans=i.first;
            }
        }
        if(mx>n/2)
            return ans;
        return -1;
    }
};