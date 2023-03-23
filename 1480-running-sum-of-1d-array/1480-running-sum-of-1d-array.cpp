class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum(0);
        vector<int> rSum;
        for(auto val:nums){
            sum+=val;
            rSum.push_back(sum);
        }
        return rSum;
    }
};