class Solution {
public:
    int longestSubsequence(vector<int>& a, int k) {
        map<int,int> dp;
        int ans=INT_MIN;
        for(int i=0;i<size(a);i++){
            dp[a[i]]=1+dp[a[i]-k];
            ans=max(ans,dp[a[i]]);
        }
        return ans;
    }
};