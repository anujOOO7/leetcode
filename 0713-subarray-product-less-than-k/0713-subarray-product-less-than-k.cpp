class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j=0;
        long long mul=1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mul*=nums[i];
            while(mul>=k && j<=i)
            {
                mul/=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;

    }
};