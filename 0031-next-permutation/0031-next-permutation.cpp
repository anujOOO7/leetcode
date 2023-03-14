class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n=nums.size(),ind=-1;
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i]<nums[i+1]){
        //         ind=i;
        //         break;
        //     }
        // }
        // for(int i=n-1;i>=ind && ind!=-1;i--){
        //     if(nums[i]>nums[ind]){
        //         swap(nums[i],nums[ind]);
        //         break;
        //     }
        // }
        // reverse(nums.begin()+ind+1,nums.end());
        next_permutation(nums.begin(),nums.end());
    }
};