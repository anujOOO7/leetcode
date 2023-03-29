class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0,sum=0,count=0,n=size(nums);
        map<int,int> mp;
        while(i<nums.size())
        {
            sum+=nums[i];
            if(sum==k) count++;
            if(mp.find(sum-k)!=mp.end())
                count+=mp[sum-k];
            mp[sum]++;
            i++;
        }
        return count;
    }
};