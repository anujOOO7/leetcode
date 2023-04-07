class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0,ans=1e9;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                if(sum>=target){
                    ans=min(ans,j-i+1);
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==1e9) return 0;
        return ans;
    }
};