class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i,j=0,count=0,mul=1;
        for(i=0;i<nums.size();i++)
        {
            mul*=nums[i];
            while(j<=i && mul>=k)
            {
                mul/=nums[j];
                j++;
            }
            count=count+(i-j+1);
        }
       return count; 
    }
};