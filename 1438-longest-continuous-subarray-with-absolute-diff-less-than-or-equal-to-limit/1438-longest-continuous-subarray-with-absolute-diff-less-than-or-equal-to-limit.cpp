class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx,mn;
        int i=0,j;
        for(j=0;j<nums.size();j++){
            while(!mx.empty() && nums[j]>mx.back()) mx.pop_back();
            mx.push_back(nums[j]);
            while(!mn.empty() && nums[j]<mn.back()) mn.pop_back();
            mn.push_back(nums[j]);
            if(mx.front()-mn.front()>limit){
                if(mx.front()==nums[i]) mx.pop_front();
                if(mn.front()==nums[i]) mn.pop_front();
                i++;
            }
        }
        return j-i;
    }
};