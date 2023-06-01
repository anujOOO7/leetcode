class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int pre=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int rem=pre%k;
            if(rem==0 && i) return true;
            if(m.count(rem)){
                int prev_ind=m[rem];
                int cur_ind=i;
                if(cur_ind-prev_ind>1) return true;
            }
            else m[rem]=i;
        }
        return 0;
    }
};