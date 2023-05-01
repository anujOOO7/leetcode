class Solution {
public:
    double average(vector<int>& nums) {
        sort(begin(nums),end(nums));
        double sum=accumulate(nums.begin()+1,nums.begin()+nums.size()-1,0);
        return sum/(nums.size()-2);
    }
};