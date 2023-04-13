class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l(-1),r(nums.size());
        while(r-l>1)
        {
            int mid=(r+l)/2;
            if(nums[mid]>nums[mid+1]) r=mid;
            else l=mid;
        }
        return r;
    }
};