class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        int n=size(nums);
        while(n>1){
            for(int i=1;i<n;i++){
                temp.push_back((nums[i]+nums[i-1])%10);
            }
            nums.clear();
            nums=temp;
            temp.clear();
            n--;
        }
        return nums[0];
    }
};