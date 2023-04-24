class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            int l=0,r=i-1;
            while(r>l){
                if(nums[l]+nums[r]>nums[i]){
                    count+=r-l;
                    r--;
                }
                else l++;
            }
        }
        return count;
    }
};