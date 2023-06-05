class Solution {
public:
    using ll=long long;
    vector<int> nums;
    vector<vector<ll>> dp;
    ll f(int i,int j){
        if(i==nums.size()) return 0;
        
        ll &d=dp[i][j];
        if(d!=-1) return d;
        ll ans=INT_MIN;
        if(!j) ans=max(nums[i]+f(i+1,1),f(i+1,0));
        else ans=max(-nums[i]+f(i+1,0),f(i+1,1));
        return d=ans;
    }
    long long maxAlternatingSum(vector<int>& arr) {
        nums=arr;
        dp.resize(arr.size()+1,vector<ll> (2,-1));
        return f(0,0);
    }
};