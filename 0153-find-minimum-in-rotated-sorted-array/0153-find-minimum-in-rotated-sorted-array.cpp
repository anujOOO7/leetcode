class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return min(nums[0],nums[1]);
        while(r-l>1){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid+1] && mid+1<n)    return nums[mid+1];
            if(nums[mid]<nums[mid-1] && mid-1>=0)   return nums[mid];
            
            if(nums[mid]>nums[l] && nums[r]>nums[mid]){
                return nums[l];
            }
            else if(nums[mid]>nums[l] && nums[r]<nums[mid]){
                l=mid;
            }
            else if(nums[mid]<nums[l] && nums[r]>nums[mid]){
                r=mid;
            }
        }
        return -1;
    }
};