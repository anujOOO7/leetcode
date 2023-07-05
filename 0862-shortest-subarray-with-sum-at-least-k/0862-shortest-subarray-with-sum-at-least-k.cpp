class Solution {
public:
    using ll=long long;
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=INT_MAX,n=nums.size();
        deque<int> d;
        vector<ll> pre(n);
        pre[0]=nums[0];
        for(int i=0;i<n;i++){
            if(i) pre[i]=nums[i]+pre[i-1];
            if(pre[i]>=k) ans=min(ans,i+1);
            while(d.size() && pre[i]-pre[d.front()]>=k){
                ans=min(ans,i-d.front());
                d.pop_front();
            }
            while(d.size() && pre[i]<=pre[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return ans==INT_MAX?-1:ans;
    }
};