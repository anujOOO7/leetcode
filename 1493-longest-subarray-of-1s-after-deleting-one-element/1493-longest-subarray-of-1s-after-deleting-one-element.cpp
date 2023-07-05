class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,cnt=0,ans=INT_MIN;
        while(r<nums.size()){
            if(nums[r]==0) cnt++;
            while(cnt>1){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,r-l);
            r++;
            // cout<<ans<<" "<<r<<endl;
        }
        return ans;
    }
};