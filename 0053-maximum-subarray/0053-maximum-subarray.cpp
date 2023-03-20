class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN,curSum=0;
        for (int i=0;i<n;i++){
            curSum+=nums[i]; 
            mx=max(mx,curSum);
            curSum=max(curSum,0);
        } 
        return mx;
    }
};