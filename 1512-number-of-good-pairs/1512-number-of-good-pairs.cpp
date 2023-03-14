class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(auto num:nums){
            m[num]++;
        }
        long long ans=0;
        for(auto [x,y]:m){
            ans+=(y*(y-1))/2;
        }
        return ans;
    }
};