class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> p(nums.size()),s(nums.size());
        int sum=0;
        p[0]=sum;
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i-1];
            p[i]=sum;
        }
        sum=0;
        s[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            sum+=nums[i+1];
            s[i]=sum;
        }
        for(int i=0;i<nums.size();i++){
            if(p[i]==s[i])
                return i;
        }
        return -1;
    }
};