class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0,maxSum=INT_MIN,cMax=0,minSum=INT_MAX,cMin=0;
        for(auto i:nums)
        {
            cMax=max(i,cMax+i);
            maxSum=max(maxSum,cMax);
            cMin=min(i,cMin+i);
            minSum=min(minSum,cMin);
            totalSum+=i;
        }
        return maxSum>0? max(maxSum,totalSum-minSum):maxSum;
    }
};