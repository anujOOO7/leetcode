class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l(-1),r(nums.size()),mid;
        while(r-l>1){
            mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid;
            else
                r=mid;
        }
        return l+1;
    }
};