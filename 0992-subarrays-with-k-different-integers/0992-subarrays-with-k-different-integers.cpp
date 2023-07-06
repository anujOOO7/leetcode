class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto f=[&](int k){
            map<int,int> m;
            int l=0,r=0,ans=0;
            while(r<nums.size()){
                m[nums[r]]++;
                while(r>=l && m.size()>k){
                    m[nums[l]]--;
                    if(m[nums[l]]==0) m.erase(nums[l]);
                    l++;
                }
                ans+=(r-l+1);
                r++;
            }
            return ans;
        };
        return f(k)-f(k-1);
    }
};